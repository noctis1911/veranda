#if QT_VERSION >= 0x050000
    #include <QApplication>
#else
    #include <QtGui/QApplication>
#endif

#include <QtCore/QCoreApplication>
#include <QDir>

#include <stdio.h>
#include <qdebug.h>

#include "util/initdb.h"

#include "controller/worker.h"

#include "model/modelmodem.h"
#include "model/db_config.h"

#include "view/skywavenetwork.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "main thread ID: " << a.thread()->currentThreadId();
#if 0
    QSqlError err = initDb();
    if (err.type() != QSqlError::NoError) {
        showErrorDB(err);
        return 0;
    }

    modelModem modemM;
    //modemM.initializeModel();

    qDebug() << "Tot modem: " << modemM.model.rowCount();
    for (int i=0; i<modemM.model.rowCount(); i++)   {
        qDebug() << "id: " << modemM.model.record(i).value("id_ship").toString()
                 << ", modem: "<< modemM.model.record(i).value("name").toString();
    }
#endif

    QString path = QDir::currentPath();
    qDebug() << path;

    db_config *db_conf = new db_config();

    Worker worker;

    return a.exec();
}
