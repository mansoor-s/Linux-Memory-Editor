#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include <QThread>

#include "Global.h"
#include "VMA.h"
#include "Result.h"
#include "Memory.h"

class Scanner : public QThread
{
Q_OBJECT

public:
	Scanner ();
	void run ();

protected:

	void scan (BYTE, int);

private:
    int s_pid;
    int s_type;
	bool s_stop;
	std::vector<Result>* s_results;

signals:
	void setProgress (int);
	void setResults (std::vector<Result>);
	void scanFailed (std::string);

public slots:
        void newScan (int, BYTE, int, int);
	void stop ();

};

#endif // SCANNER_H
