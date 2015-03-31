#include "worker.h"

extern struct xmll xmls;

Worker::Worker(QObject *parent) : QObject(parent){
    connect(&timer, SIGNAL(timeout()), this, SLOT(doWork()));

    this->doWork();
    timer.start(5000);
    this->getResponSkyW();
}

void Worker::doWork() {
    QDateTime dateTime = QDateTime::currentDateTime();

    qDebug() << "waktu:"<<dateTime.toString();

    skywaveNetwork skw;
    //skw.requestData("wdwd");
    skw.wait();
}


void Worker::getResponSkyW(){
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));
    qDebug()<< __FUNCTION__;

    QNetworkRequest request;
    QUrl url =  QUrl::fromEncoded("http://isatdatapro.skywave.com/GLGW/GWServices_v1/RestMessages.svc/get_return_messages.xml/?access_id=70000214&password=STSATI2010&start_utc=2015-03-08%2000:35:00&mobile_id=01050309SKYA416");
    //QUrl url =  QUrl::fromEncoded("http://localhost");
    request.setUrl(url);
    manager->get(request);
    //qDebug()<<"Waiting Connection...";
}

void Worker::replyFinished(QNetworkReply* reply){
    QString readAll=reply->readAll();

    QSqlDatabase db;

    read->parse_xml(readAll, db);

//    if(readAll!=0){
//        qDebug("Your Connection OK!!!...");
//        QThread::sleep(3);

//        QDateTime dateTime = QDateTime::currentDateTime();
//        qDebug() << "SELESAI replay waktu:"<<dateTime.toString();
//        QThread::sleep(3);

//        qDebug()<<"is Reading Data!!!"<<readAll;
//        util_skyw bacaxml;
//        bacaxml.baca_xml(readAll);

//        qDebug() << "  jumlah RawPayload : " << xmls.jml;
//        }else if(readAll== NULL){
//        qDebug("Check Your Connection !!!");
//    }


    // --> insert database.
}

//void Worker::getUpdateData(){
//    QNetworkAccessManager *update = new QNetworkAccessManager();

//    connect(update, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));
//    qDebug()<< __FUNCTION__;

//    QNetworkRequest request;
//    QUrl url =  QUrl::fromEncoded("http://isatdatapro.skywave.com/GLGW/GWServices_v1/RestMessages.svc/get_return_messages.xml/?access_id=70000214&password=STSATI2010&from_id=1450235&start_utc=2015-03-16%2000:35:00&mobile_id=01020268SKY7559");
//    //QUrl url =  QUrl::fromEncoded("http://localhost");
//    request.setUrl(url);
//    update->get(request);
//    qDebug()<<"Waiting Data...";
//}
//void Worker::replyUpdate(QNetworkReply *reply){
//    QString readAll=reply->readAll();

//    if(readAll!=0){

//        QDateTime dateTime = QDateTime::currentDateTime();
//        qDebug() << "Selesai Update Data!!! replay waktu:"<<dateTime.toString();
//        QThread::sleep(5);
//        qDebug()<<"is Reading New Data!!!"<<readAll;
//        util_skyw bacaxml;
//        bacaxml.baca_xml(readAll);

//        qDebug() << "  jumlah RawPayload : " << xmls.jml;
//        }else if(readAll== NULL){
//        qDebug("Check Your Connection !!!");

//    }
//}


