#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent),
ui(new Ui::MainWindow)
{
    //scanner declared in mainwindow.h
    scanner = new Scanner;

    //scanner is initialized before GUI
    scanner->start();

    ui->setupUi(this);

    // to get progress value from the scanner thread
    connect(scanner, SIGNAL(setProgress(int)), ui->progressBar, SLOT(setValue(int)), Qt::AutoConnection);
    // to start the initial scanning
    connect(this, SIGNAL(startNewScan(int, BYTE, int, int)), scanner, SLOT(newScan(int, BYTE, int, int)), Qt::AutoConnection);
    // to be able to cancel a scan in progress
    connect(this, SIGNAL(stopScan()), scanner, SLOT(stop()), Qt::AutoConnection);
    // to be able to show the user what went wrong with the scanning
    connect(scanner, SIGNAL(scanFailed(std::string)), this, SLOT(scanFailed(std::string)), Qt::AutoConnection);
    // to get the results of the completed scan
    connect(scanner, SIGNAL(setResults(std::vector<Result>)) , this, SLOT(scanFinished(std::vector<Result>)), Qt::AutoConnection);

    ui->pushButton_next->setDisabled(true);
    ui->pushButton_stop->setDisabled(true);
    ui->pushButton_undo->setDisabled(true);
    ui->progressBar->setValue(0);

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
	QMainWindow::changeEvent(e);

		switch (e->type())
		{
			case QEvent::LanguageChange:
			ui->retranslateUi(this);
			break;
			default:
				
			break;
		}

}

void MainWindow::setTarget(QMap<int, QString> target)
{
	targetProc = target;
}

void MainWindow::showProcessList()
{
	ProcessList* pl = new ProcessList(this);
	pl->setModal(true);
	pl->show();
}


void MainWindow::enableScan()
{
   ui->pushButton_scan->setEnabled(true);
}



void MainWindow::firstScan()
{
    // we could do without this	but it keeps the code easy to read
#define CONTROL_STATEMENT   \
    buffValue = new unsigned char[sizeof(testValue)]; \
                memcpy(buffValue, &testValue, sizeof(testValue));

    ui->pushButton_scan->setDisabled(true);

    int pid = targetProc.keys().at(0);

    ui->pushButton_stop->setEnabled(true);
    foundAddresses = new std::vector<Result>;

    // determine the operation type from the UI
    int operation = ui->searchOperationCombo->currentIndex();
    switch(operation) {
    case 0:
        operation = EXACT;
        break;
    case 1:
        operation = GREATER;
        break;
    case 2:
        operation = LESSER;
        break;
    case 3:
        operation = CHANGED;
        break;
    case 4:
        operation = UNCHANGED;
        break;
    case 5:
        operation = UNKNOWN;
        break;
    }

    //determine the value to search for and it's data-type
    BYTE buffValue;
    QString value = ui->valueEdit->text();
    int valueType = ui->dataTypeCombo->currentIndex();
    qDebug() << "valueType: " << valueType << " value: " << value;
    if(valueType == 0) {
        valueType = BOOLEAN;
        bool testValue;
        if(value.toLower() == "true" || value.toInt() != 0)
            testValue = true;
        else
            testValue = false;
        CONTROL_STATEMENT
            }
    else if(valueType == 0) {
        valueType = CHARACTER;
        char testValue = value.toLatin1().at(0);
        CONTROL_STATEMENT
            }
    else if(valueType == 1) {
        valueType = SHORT_INTEGER;
        short testValue = value.toShort();
        CONTROL_STATEMENT
            }
    else if(valueType == 2) {
        valueType = INTEGER;
        int testValue = value.toInt();
        CONTROL_STATEMENT
            }
    else if(valueType == 3) {
        valueType = LONG_INTEGER;
        long testValue = value.toLong();
        CONTROL_STATEMENT
            }
    else if(valueType == 4) {
        valueType = FLOAT;
        float testValue = value.toFloat();        
        CONTROL_STATEMENT

            }
    else if(valueType == 6) {
        valueType = DOUBLE;
        double testValue = value.toDouble();
    }
    else if(valueType == 7) {
        valueType = STRING;
        char* testValue = value.toLatin1().data();
        CONTROL_STATEMENT
            }
    else if(valueType == 8) {
        valueType = UNICODE_CHARECTER;
        wchar_t testValue[value.size()]; // = new wchar_t;
        mbtowc(testValue, (const char*)value.toUtf8().data()[0], sizeof(value.toUtf8().data()[0]));
        CONTROL_STATEMENT
            }
    else if(valueType == 9) {
        valueType = UNICODE_STRING;
        wchar_t *testValue = new wchar_t;
        mbstowcs(testValue, value.toUtf8().data(), value.size());
        CONTROL_STATEMENT
            }



    emit startNewScan(pid, buffValue, valueType, operation);
}

void MainWindow::nextScan()
{
   //((Result)foundAddresses->at(1)).getData()
}

void MainWindow::scanFinished(std::vector<Result> results)
{

		for(int i = 0; i < results.size(); i++)
		{
			QTableWidgetItem *address = new QTableWidgetItem(QString::number(static_cast<Result>(results.at(i)).baseAddr(),16));
			QTableWidgetItem *currentValue = new QTableWidgetItem(QString((char*)static_cast<Result>(results.at(i)).data()));
			ui->tableWidget->setItem(i,0,address);
			ui->tableWidget->setItem(i,1,currentValue);
		}

	ui->pushButton_next->setEnabled(true);

}

void MainWindow::scanFailed(std::string errorMsg)
{
	error(QString(errorMsg.c_str()));
}

void MainWindow::error(QString message)
{
	QMessageBox info;
	info.setIcon(QMessageBox::Critical);
	info.setText(message);
	info.exec();
}
