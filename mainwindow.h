#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThreadPool>
#include <QList>
#include <QtConcurrentMap>
#include <stdlib.h>
#include <QMessageBox>

#include "ProcessList.h"
#include "Memory.h"
#include "VMA.h"
#include "Result.h"
#include "Scanner.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
	MainWindow (QWidget* parent = 0);
	~MainWindow ();
	void setTarget (QMap<int, QString> target);
	void enableScan ();


protected:
	void changeEvent (QEvent* e);

private:
    Ui::MainWindow* ui;
    QMap<int, QString> targetProc;
    std::vector<Result> *foundAddresses;
    Scanner* scanner;
    void error(QString);

signals:
    void startNewScan (int, BYTE, int, int);
    void stopScan ();

public slots:
    void scanFinished (std::vector<Result>);
    void scanFailed (std::string);

private slots:
    void showProcessList ();
    void firstScan ();
    void nextScan ();
};

#endif // MAINWINDOW_H
