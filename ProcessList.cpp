#include "ProcessList.h"
#include "ui_ProcessList.h"
#include <QDebug>
#include <iostream>
#include <QMainWindow>
#include "mainwindow.h"

ProcessList::ProcessList(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::ProcessList)
{

    ui->setupUi(this);
    //    ui->tableWidget->setColumnCount(2);
    //    QTableWidgetItem *header0 = new QTableWidgetItem(QString("PID"));
    //    QTableWidgetItem *header1 = new QTableWidgetItem(QString("Process name"));
    //    ui->tableWidget->setHorizontalHeaderItem(0,header0);
    //    ui->tableWidget->setHorizontalHeaderItem(1,header1);

    QHeaderView *headerLayout = new QHeaderView(Qt::Horizontal,ui->tableWidget);
    headerLayout->setResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setHorizontalHeader(headerLayout);

    try {
        QMap<int, QString> processList;
        processList = getCurrentProcesses();
        if(processList.count() < 1) {
            throw(QString("Process list is empty!"));
        }
        ui->tableWidget->setRowCount(processList.count());
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableWidget->setColumnWidth(0,ui->tableWidget->width()/2);

        QMapIterator<int, QString> i(processList);
        int j = 0;
        while(i.hasNext()){

            i.next();
            QTableWidgetItem *processPID = new QTableWidgetItem(QString::number(i.key(),10));
            QTableWidgetItem *processName = new QTableWidgetItem(QString(i.value()));
            ui->tableWidget->setItem(j,0,processPID);
            ui->tableWidget->setItem(j,1,processName);
            j++;
        }
    } catch(QString e) {
        qDebug() << e;
    }

    ui->label_user->setText(currUser);
}

/*
  *
  * read and parse ps -u $CURRENTUSER$ f
  * and return the PID and proess name
  * also sets (private) currUser (used in UI)
  */
QMap<int, QString> ProcessList::getCurrentProcesses() {
    QMap<int, QString> *processList = new QMap<int, QString>;
    int PID;
    char buffer[256] = {0};
    // get current user
    FILE *proc = popen("whoami", "r");
    fgets(buffer,sizeof(buffer),proc);
    pclose(proc);
    char buff2[256] = {0};
    strncpy(buff2, buffer, strlen(buffer)-1); // get rid of the new line char
    currUser = QString(buff2);
    sprintf(buffer, "ps -u %s -f", buff2);
    proc = popen(buffer,"r");

    for(;fgets(buff2, sizeof(buff2),proc);) {
        strncpy(buffer, "\0",1);
        // we only need PID and process name
        sscanf(buff2,"%*s %d %*d %*s %*s %*s %*s %s", &PID, buffer );
        if(strlen(buffer) != 0) {
            processList->insert(PID, QString(buffer));
        }
    }
    return *processList;
}

ProcessList::~ProcessList()
{
    delete ui;
}

void ProcessList::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ProcessList::exit()
{
    this->close();

}

/*
  * Gives the MainWindow class back the PID and the Name of the application that the user has selected
  *
  */
void ProcessList::selectProc()
{
    QMap<int, QString> targetProcess;

    int row = ui->tableWidget->currentItem()->row();

    QTableWidgetItem *cell = ui->tableWidget->item(row,0);

    int pid = cell->text().toInt();
    cell = ui->tableWidget->item(row,1);

    QString procName = cell->text();
    targetProcess[pid] = procName;

    ((MainWindow *) parentWidget())->setTarget(targetProcess);
    ((MainWindow *) parentWidget())->setWindowTitle(((MainWindow *) parentWidget())->windowTitle() + " - " + procName);

    // enable the first scan button which will the enable the rest of the controls
    ((MainWindow *) parentWidget())->enableScan();

    this->close();
}
