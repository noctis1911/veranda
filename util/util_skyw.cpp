#include "util_skyw.h"

struct xmll xmls;

util_skyw::util_skyw(QObject *parent) :
    QObject(parent)
{
}

void util_skyw::parse_xml(QString skyw, QSqlDatabase db)  {
    int cnt = 0;
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
            //qDebug()<<"  xmlname: "<<xml.name().toString();

            if(xml.name() == "ID") {
                cnt = 0;
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
            if(xml.name() == "Field") {
                QXmlStreamAttributes attributes = xml.attributes();
                int value = attributes.value("Value").toString().toInt();

                float data_f = *(float *) &value;

                if (cnt == 0){
                    const QDateTime time = QDateTime::fromTime_t((int)data_f);
                    QString epochtime = time.toString("yyyy-MM-dd hh:mm:ss").toAscii().data();

                    qDebug() << epochtime;
                    cnt = 1;
                }
                else{
                    qDebug() << data_f;
                }
            }
        }
    }
}
