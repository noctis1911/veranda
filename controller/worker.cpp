#include "worker.h"

extern struct xmll xmls;

Worker::Worker(QObject *parent, QSqlDatabase db) : QObject(parent){
    //connect(&timer, SIGNAL(timeout()), this, SLOT(doWork()));
    //timer.start(5000);

    Qdb = db;
    cek_replay = 0;

    idx_ship = 1;
    sum_ship = get->sum_ship(db);
    //this->get_modem_info(db, idx_ship);

    this->doWork();
}

void Worker::doWork() {
    QDateTime dateTime = QDateTime::currentDateTime();
    qDebug() << "waktu:"<<dateTime.toString();

    this->get_modem_info(Qdb, idx_ship);
    this->getResponSkyW();

    //skywaveNetwork skw;
    //skw.requestData("wdwd");
    //skw.wait();
}


void Worker::getResponSkyW(){
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));
    qDebug()<< __FUNCTION__;

    QNetworkRequest request;

    QString urls;
    urls.sprintf("http://isatdatapro.skywave.com/GLGW/GWServices_v1/RestMessages.svc/get_return_messages.xml/?access_id=%s&password=%s&start_utc=2015-04-01%2015:30:00&mobile_id=%s", access_id.toAscii().data(), password.toAscii().data(), modem_id.toAscii().data());
    QUrl url =  QUrl::fromEncoded(urls.toAscii().data());
    //QUrl url =  QUrl::fromEncoded("http://localhost");
    request.setUrl(url);
    manager->get(request);
    //qDebug()<<"Waiting Connection...";
}

void Worker::replyFinished(QNetworkReply* reply){
    QString readAll=reply->readAll();

    read->parse_xml(readAll, Qdb, idx_ship);
    // --> insert database.

    qDebug() << ">>>>>>>>>>>>>>>>>>>>>>>>> HABIS <<<<<<<<<<<<<<<<<<<<<<<<";
    if (idx_ship != sum_ship){
        idx_ship++;
        this->doWork();
    }else{
        idx_ship = 1;
        qDebug() << " ------------------------ STOP -------------------------";
    }
}

void Worker::get_modem_info(QSqlDatabase db, int id){
    QSqlQuery q(db);
    QString query;
    query.sprintf("select modem_id, access_id, password from ship where id = %d", id);
    q.prepare(query);
    if(!q.exec()){
        qDebug() << "err():";
        return;
    }
    else{
        while(q.next()){
            modem_id = q.value(0).toString();
            access_id = q.value(1).toString();
            password = q.value(2).toString();
        }
    }
}
