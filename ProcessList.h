#ifndef PROCESSLIST_H
#define PROCESSLIST_H

#include <QDialog>
#include <QMap>
#include <stdio.h>
namespace Ui {
    class ProcessList;
}


class ProcessList : public QDialog {
Q_OBJECT

public:
    ProcessList(QWidget *parent = 0);
    ~ProcessList();


protected:
    void changeEvent(QEvent *e);
    QMap<int, QString> getCurrentProcesses();

private:

    Ui::ProcessList *ui;
	QString currUser;

private slots:
    void exit();
    void selectProc();
};

#endif // PROCESSLIST_H
