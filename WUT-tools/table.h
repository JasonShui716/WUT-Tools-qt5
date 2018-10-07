#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QTableWidget>
#include <vector>

class Table : public QObject
{
    Q_OBJECT
public:
    explicit Table(QObject *parent = nullptr);
    void showDialog(QString title);
    void drawTable(int x, int y, QStringList xLv, QStringList yLv);
    void fillInTable(QString path);
signals:

public slots:

private:
    QTableWidget *pTable;
};

#endif // TABLE_H
