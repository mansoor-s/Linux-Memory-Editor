/****************************************************************************
** Meta object code from reading C++ file 'Scanner.h'
**
** Created: Sun Apr 3 23:44:36 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Scanner.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Scanner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Scanner[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      26,    8,    8,    8, 0x05,
      58,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      86,   82,    8,    8, 0x0a,
     112,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Scanner[] = {
    "Scanner\0\0setProgress(int)\0"
    "setResults(std::vector<Result>)\0"
    "scanFailed(std::string)\0,,,\0"
    "newScan(int,BYTE,int,int)\0stop()\0"
};

const QMetaObject Scanner::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Scanner,
      qt_meta_data_Scanner, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Scanner::getStaticMetaObject()
{
	return staticMetaObject;
}
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Scanner::metaObject() const
{
	return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Scanner::qt_metacast(const char *_clname)
{

		if (!_clname) return 0;
		if (!strcmp(_clname, qt_meta_stringdata_Scanner))

	return static_cast<void*>(const_cast< Scanner*>(this));
	return QThread::qt_metacast(_clname);
}

int Scanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
	_id = QThread::qt_metacall(_c, _id, _a);

		if (_id < 0)
		{
			return _id;
		}

		if (_c == QMetaObject::InvokeMetaMethod)
		{
			switch (_id)
			{
				case 0:
					setProgress((*reinterpret_cast< int(*)>(_a[1])));
				break;
				case 1:
					setResults((*reinterpret_cast< std::vector<Result>(*)>(_a[1])));
				break;
				case 2:
					scanFailed((*reinterpret_cast< std::string(*)>(_a[1])));
				break;
				case 3:
					newScan((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< BYTE(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
				break;
				case 4:
					stop();
				break;
				default: ;
			}
		_id -= 5;
		}

	return _id;
}

// SIGNAL 0
void Scanner::setProgress(int _t1)
{
	void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
	QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Scanner::setResults(std::vector<Result> _t1)
{
	void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
	QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Scanner::scanFailed(std::string _t1)
{
	void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
	QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

QT_END_MOC_NAMESPACE