#include "table.h"
#include <QFile>

Table::Table(QObject *parent) : QObject(parent)
{

}

void Table::showDialog(QString title){
    QDialog *dialog = new QDialog;
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle(title);
    dialog->show();
}

void Table::drawTable(int x, int y,  QStringListxLv,  QStringListyLv){
    pTable = new QTableWidget(x, y);
    pTable->setVerticalHeaderLabels(xLv);
    pTable->setHorizontalHeaderLabels(yLv);
}

void Table::fillInTable(QString path){
    QFile file(path);
}

Table::~Table()
{

}
