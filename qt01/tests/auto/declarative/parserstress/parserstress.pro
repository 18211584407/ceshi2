load(qttest_p4)
contains(QT_CONFIG,declarative): QT += declarative
macx:CONFIG -= app_bundle

SOURCES += tst_parserstress.cpp

wince*|symbian: {
    importFiles.files = ..\\..\\qscriptjstestsuite\\tests
    importFiles.path = .
    DEPLOYMENT += importFiles
    wince*: DEFINES += SRCDIR=\\\".\\\"
} else {
    DEFINES += SRCDIR=\\\"$$PWD\\\"
}

CONFIG += parallel_test

