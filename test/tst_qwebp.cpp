/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtAddOn.ImageFormats module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
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
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtTest/QtTest>
#include <QtGui/QtGui>

class tst_qwebp : public QObject
{
    Q_OBJECT

private slots:
    void initTestcase();
    void readImage_data();
    void readImage();
    void writeImage_data();
    void writeImage();
    void readAnimatedImage_data();
    void readAnimatedImage();
};

void tst_qwebp::initTestcase()
{
    // Make it prior to Qt built-in webp plugin
    QCoreApplication::removeLibraryPath(QCoreApplication::applicationDirPath());
    QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath());
}

void tst_qwebp::readImage_data()
{
    QTest::addColumn<QString>("fileName");
    QTest::addColumn<QSize>("size");

    QTest::newRow("kollada") << QString("kollada") << QSize(436, 160);
    QTest::newRow("kollada_lossless") << QString("kollada_lossless") << QSize(436, 160);
}

void tst_qwebp::readImage()
{
    QFETCH(QString, fileName);
    QFETCH(QSize, size);

    const QString path = QStringLiteral(":/images/") + fileName + QStringLiteral(".webp");
    QImageReader reader(path);
    QVERIFY(reader.canRead());
    QVERIFY(!reader.supportsAnimation());
    QCOMPARE(reader.imageCount(), 1);
    QCOMPARE(reader.loopCount(), 0);
    QImage image = reader.read();
    QVERIFY2(!image.isNull(), qPrintable(reader.errorString()));
    QCOMPARE(image.size(), size);
}

void tst_qwebp::writeImage_data()
{
    QTest::addColumn<QString>("fileName");
    QTest::addColumn<QString>("postfix");
    QTest::addColumn<int>("quality");
    QTest::addColumn<QSize>("size");
    QTest::addColumn<bool>("needcheck");

    QTest::newRow("kollada-75") << QString("kollada") << QString(".png") << 75 << QSize(436, 160) << false;
    QTest::newRow("kollada-100") << QString("kollada") << QString(".png") << 100 << QSize(436, 160) << true;
}

void tst_qwebp::writeImage()
{
    QFETCH(QString, fileName);
    QFETCH(QString, postfix);
    QFETCH(int, quality);
    QFETCH(QSize, size);
    QFETCH(bool, needcheck);

    const QString path = QString("%1-%2.webp").arg(fileName).arg(quality);
    const QString sourcePath = QStringLiteral(":/images/") + fileName + postfix;

    QImage image(sourcePath);
    QVERIFY(!image.isNull());
    QVERIFY(image.size() == size);

    QImageWriter writer(path, QByteArrayLiteral("webp"));
    QVERIFY2(writer.canWrite(), qPrintable(writer.errorString()));
    writer.setQuality(quality);
    QVERIFY2(writer.write(image), qPrintable(writer.errorString()));

    if (needcheck)
        QVERIFY(image == QImage(path));
}

void tst_qwebp::readAnimatedImage_data()
{
    QTest::addColumn<QString>("fileName");
    QTest::addColumn<QSize>("imageSize");
    QTest::addColumn<int>("loop");
    QTest::addColumn<QList<QSize> >("frameSizes");
    QTest::addColumn<QList<int> >("durations");

    QTest::newRow("kollada_anim") << QString("kollada_anime") << QSize(446, 170) << 10
        << (QList<QSize>() << QSize(436, 160) << QSize(436, 160))
        << (QList<int>() << 50 << 100);
}

void tst_qwebp::readAnimatedImage()
{
    QFETCH(QString, fileName);
    QFETCH(QSize, imageSize);
    QFETCH(int, loop);
    QFETCH(QList<QSize>, frameSizes);
    QFETCH(QList<int>, durations);

    const QString path = QStringLiteral(":/images/") + fileName + QStringLiteral(".webp");
    QImageReader reader(path);
    QVERIFY(reader.canRead());
    QVERIFY(reader.supportsAnimation());
    QCOMPARE(reader.size(), imageSize);
    QCOMPARE(reader.imageCount(), frameSizes.count());
    QCOMPARE(reader.loopCount(), loop);

    for (int i = 0; i < reader.imageCount(); ++i) {
        QImage image = reader.read();
        QVERIFY2(!image.isNull(), qPrintable(reader.errorString()));
        QCOMPARE(image.size(), frameSizes[i]);
        QCOMPARE(reader.nextImageDelay(), durations[i]);
    }

    QVERIFY(reader.read().isNull());
}

QTEST_MAIN(tst_qwebp)
#include "tst_qwebp.moc"
