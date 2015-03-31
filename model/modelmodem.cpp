#include "modelmodem.h"

modelModem::modelModem(QObject *parent) : QSqlTableModel(parent)    {
    model.setQuery("SELECT * FROM ship");
    //QString sdsd = "call overhaul";
    //model.setQuery(sdsd);
    if (model.lastError().isValid())
        qDebug() << "Error: " << model.lastError();
}


