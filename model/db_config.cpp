#include "db_config.h"

db_config::db_config()
{
    count_db = 1;
}

QSqlDatabase db_config::cek_exist_db(QString fileName){
    QFile file(fileName+".db");

    if (file.exists() == true){
        return (QSqlDatabase) this->load_db(fileName+".db", count_db);
    }
    else{
        return (QSqlDatabase) this->create_db(fileName, count_db);
    }
}

QSqlDatabase db_config::create_db(QString fileName, int count_db)
{
    QString con_name;
    con_name.sprintf("LOC_DB%d", count_db++);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", con_name);
    db.setDatabaseName(fileName+".db"); //tambah ekstensi ".ovm" pada nama database

    if (!db.open())
    {
        qDebug() << "db corrupt! create";
        return (QSqlDatabase) db;
    }
    else
    {
        QSqlQuery query( db );
        this->crt_table_ship(db);
        this->crt_table_parsing(db);
        this->crt_table_data(db);
        query.finish();

        return (QSqlDatabase) db;
    }
}

QSqlDatabase db_config::load_db(QString fileName, int count_db)
{
    QString con_name;
    con_name.sprintf("LOC_DB%d", count_db++);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", con_name);
    db.setDatabaseName(fileName);

    if (!db.open()){
        qDebug() << "db corupt! load";
        return (QSqlDatabase) db;
    }
    else{
        return (QSqlDatabase) db;
    }
}


void db_config::crt_table_ship(QSqlDatabase db){
    QSqlQuery q(db);
    q.prepare("create table ship (id integer primary key autoincrement, name varchar[32], modem_id varchar[32], access_id varchar[32], password varchar[32], SIN integer, MIN integer)"); q.exec();

    q.prepare("insert into ship(name, modem_id, access_id, password, SIN, MIN) values('AHTS Kittiwake', '01050309SKYA416', '70000214', 'STSATI2010', 128, 1)"); q.exec();
    q.prepare("insert into ship(name, modem_id, access_id, password, SIN, MIN) values('AHTS Pelangi Escort 2', '01020268SKY7559', '70000214', 'STSATI2010', 128, 1)"); q.exec();
    q.prepare("insert into ship(name, modem_id, access_id, password, SIN, MIN) values('AHTS Temasek Sepinggan', '01050256SKY4F0D','70000214', 'STSATI2010', 128, 1)"); q.exec();
    q.prepare("insert into ship(name, modem_id, access_id, password, SIN, MIN) values('AHTS Temasek Attaka', '01050294SKYE7CB', '70000214', 'STSATI2010', 128, 1)"); q.exec();
}

void db_config::crt_table_data(QSqlDatabase db){
    QSqlQuery q(db);
    q.prepare("create table data (id integer primary key autoincrement, id_tu integer, value float, id_trip integer, data_time DATETIME)"); q.exec();
}

void db_config::crt_table_parsing(QSqlDatabase db){
    QSqlQuery q(db);
    q.prepare("create table parsing_ref (id integer primary key autoincrement, id_ship integer, urutan_data_monita integer, id_tu integer)"); q.exec();

    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,1,1001)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,2,1002)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,3,1004)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,4,1003)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,5,1007)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,6,1005)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,7,1017)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,8,1009)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,9,1011)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,10,1010)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,11,1008)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,12,1012)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,13,1006)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,14,1018)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,15,1013)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,16,1015)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,17,1014)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,18,1016)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,19,1019)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(1,20,1020)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,1,2001)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,2,2002)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,3,2004)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,4,2003)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,5,2007)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,6,2008)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,7,2005)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,8,2006)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,9,2017)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,10,2018)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,11,2009)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,12,2011)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,13,2010)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,14,2012)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,15,2013)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,16,2015)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,17,2014)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,18,2016)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,19,2019)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(2,20,2020)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,8,3005)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,1,3001)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,2,3002)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,3,3003)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,4,3004)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,7,3006)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,6,3007)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,5,3008)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,11,3009)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,13,3010)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,12,3011)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,14,3012)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,15,3013)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,17,3014)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,16,3015)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,18,3016)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,9,3017)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,10,3018)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,19,3019)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(3,20,3020)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,1,4001)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,2,4002)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,3,4003)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,4,4004)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,6,4005)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,5,4006)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,8,4007)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,7,4008)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,13,4009)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,11,4010)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,14,4011)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,12,4012)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,15,4013)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,17,4014)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,16,4015)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,18,4016)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,9,4017)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,10,4018)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,19,4019)"); q.exec();
    q.prepare("insert into parsing_ref(id_ship, urutan_data_monita, id_tu) values(4,20,4020)"); q.exec();
}
