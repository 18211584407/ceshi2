/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtTest/QtTest>

#include <QtMultimedia/QAbstractVideoBuffer>

class tst_QAbstractVideoBuffer : public QObject
{
    Q_OBJECT
public:
    tst_QAbstractVideoBuffer();
    ~tst_QAbstractVideoBuffer();

public slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

private slots:
    void handleType_data();
    void handleType();
    void handle();
};

class QtTestVideoBuffer : public QAbstractVideoBuffer
{
public:
    QtTestVideoBuffer(QAbstractVideoBuffer::HandleType type) : QAbstractVideoBuffer(type) {}

    MapMode mapMode() const { return NotMapped; }

    uchar *map(MapMode, int *, int *) { return 0; }
    void unmap() {}
};

tst_QAbstractVideoBuffer::tst_QAbstractVideoBuffer()
{
}

tst_QAbstractVideoBuffer::~tst_QAbstractVideoBuffer()
{
}

void tst_QAbstractVideoBuffer::initTestCase()
{
}

void tst_QAbstractVideoBuffer::cleanupTestCase()
{
}

void tst_QAbstractVideoBuffer::init()
{
}

void tst_QAbstractVideoBuffer::cleanup()
{
}

void tst_QAbstractVideoBuffer::handleType_data()
{
    QTest::addColumn<QAbstractVideoBuffer::HandleType>("type");

    QTest::newRow("none")
            << QAbstractVideoBuffer::NoHandle;
    QTest::newRow("opengl")
            << QAbstractVideoBuffer::GLTextureHandle;
    QTest::newRow("user1")
            << QAbstractVideoBuffer::UserHandle;
    QTest::newRow("user2")
            << QAbstractVideoBuffer::HandleType(QAbstractVideoBuffer::UserHandle + 1);
}

void tst_QAbstractVideoBuffer::handleType()
{
    QFETCH(QAbstractVideoBuffer::HandleType, type);

    QtTestVideoBuffer buffer(type);

    QCOMPARE(buffer.handleType(), type);
}

void tst_QAbstractVideoBuffer::handle()
{
    QtTestVideoBuffer buffer(QAbstractVideoBuffer::NoHandle);

    QVERIFY(buffer.handle().isNull());
}

QTEST_MAIN(tst_QAbstractVideoBuffer)

#include "tst_qabstractvideobuffer.moc"
