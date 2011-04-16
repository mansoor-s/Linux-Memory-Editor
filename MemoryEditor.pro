# -------------------------------------------------
# Project created by QtCreator 2010-06-17T00:09:56
# -------------------------------------------------
QT += network \
    xml
TARGET = MemoryEditor
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    Memory.cpp \
    ProcessList.cpp \
    Scanner.cpp
HEADERS += mainwindow.h \
    Memory.h \
    VMA.h \
    ProcessList.h \
    Result.h \
    Global.h \
    Scanner.h
FORMS += mainwindow.ui \
    ProcessList.ui
RESOURCES += Resource.qrc
