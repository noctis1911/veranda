#include "util_skyw.h"

struct xmll xmls;

util_skyw::util_skyw(QObject *parent) :
    QObject(parent)
{
}

void util_skyw::parse_xml(QString skyw, QSqlDatabase db, int id_ship)  {
    int cnt = 0;
    int cnt_tu = 1;
    QString epochtime;
    QString el;
    QXmlStreamReader xml;
    QByteArray text;

    xml.clear();
    xml.addData(skyw);

    while(!xml.atEnd() &&  !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
        /*
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }
        //*/
        if(token == QXmlStreamReader::StartElement) {
            if(xml.name() == "ID") {
                QString ID = xml.readElementText();
                qDebug()<<"  xmlname: "<<xml.name().toString()<<":"<< ID;
            }
            if(xml.name() == "ReceiveUTC") {
                QString ReceiveUTC = xml.readElementText();
                qDebug()<<"  xmlname: "<<xml.name().toString()<<":"<< ReceiveUTC;
                xmls.st_xmls.receiveUTC = ReceiveUTC;
            }
            if(xml.name() == "SIN") {
                qDebug()<<"  xmlname: "<<xml.name().toString()<<":"<<xml.readElementText();
            }
            if(xml.name() == "MobileID") {
                QString MobileID = xml.readElementText();
                qDebug()<<"  xmlname: "<<xml.name().toString()<<":"<< MobileID;
                xmls.mobile_id = MobileID;
            }
            if(xml.name() == "Payload"){
                cnt = 0;
                cnt_tu = 1;
            }
            if(xml.name() == "Field") {
                QXmlStreamAttributes attributes = xml.attributes();
                int value = attributes.value("Value").toString().toInt();

                float data_f = *(float *) &value;

                if (cnt == 0){
                    const QDateTime time = QDateTime::fromTime_t((int)data_f);
                    epochtime = time.toString("yyyy-MM-dd hh:mm:ss").toAscii().data();

                    qDebug() << epochtime;
                    cnt = 1;
                }
                else{
                    int id_tu = get.id_tu_ship(db, id_ship, cnt_tu);

                    switch (id_tu){
                    case 0:
                        break;
                    default:
                        qDebug() <<"  data: "<<" [id_tu]: "<<id_tu<<" [value]: "<<data_f;
                        save.data(db, data_f, id_tu, 0, epochtime);
                        break;
                    }
                    cnt_tu++;
                }
            }
        }
    }
}
