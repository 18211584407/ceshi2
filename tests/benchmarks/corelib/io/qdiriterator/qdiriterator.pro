load(qttest_p4)
TEMPLATE = app
TARGET = tst_bench_qdiriterator
DEPENDPATH += .
INCLUDEPATH += .

QT -= gui

CONFIG += release

SOURCES += main.cpp

SOURCES += qfilesystemiterator.cpp
HEADERS += qfilesystemiterator.h

wince*|symbian: {
   corelibdir.files = $$QT_SOURCE_TREE/src/corelib
   corelibdir.path = ./depot/src
   DEPLOYMENT += corelibdir
}

