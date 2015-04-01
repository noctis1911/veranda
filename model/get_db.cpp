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

int get_db::id_tu_ship(QSqlDatabase db, int id_ship, int urutan){
    QSqlQuery q(db);
    QString query;

    query.sprintf("select id_tu from parsing_ref where id_ship = %d and urutan_data_monita = %d", id_ship, urutan);

    q.prepare(query);
    if(!q.exec()){
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
