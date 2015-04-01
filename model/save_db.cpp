#include "save_db.h"

save_db::save_db()
{
}

void save_db::data(QSqlDatabase db, float value, int id_tu, int id_trip, QString data_time){
    QSqlQuery q(db);

    q.prepare("insert into data(id_tu, value, id_trip, data_time) values(:id_tu, :value, :id_trip, :data_time)");

    q.bindValue(":id_tu", id_tu);
    q.bindValue(":value", value);
    q.bindValue(":id_trip", id_trip);
    q.bindValue(":data_time", data_time.toAscii().data());

    q.exec();
}
