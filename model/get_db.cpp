#include "get_db.h"

get_db::get_db()
{
}

int get_db::sum_ship(QSqlDatabase db){
    QSqlQuery q(db);

    q.prepare("select count(id) from ship");
    if (!q.exec()){
        qDebug() << "err():";
        return (int) 0;
    }
    else{
        while(q.next()){
            return (int) q.value(0).toInt();
        }
    }
}

void get_db::modem_info(QSqlDatabase db, int id, QString modem_id, QString access_id, QString password){
    QSqlQuery q(db);
    QString query;


    query.sprintf("select modem_id, access_id, password where id = %d", id);

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
