/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the WebP plugins in the Qt ImageFormats module.
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

#ifndef QWEBPHANDLER_P_H
#define QWEBPHANDLER_P_H

#include <QtGui/qimageiohandler.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qsize.h>

#include "webp/decode.h"
#include "webp/demux.h"

class QWebpHandler : public QImageIOHandler
{
public:
    QWebpHandler();
    ~QWebpHandler();

public:
    QByteArray name() const;

    bool canRead() const;
    bool read(QImage *image);

    static bool canRead(QIODevice *device);

    bool write(const QImage &image);
    QVariant option(ImageOption option) const;
    void setOption(ImageOption option, const QVariant &value);
    bool supportsOption(ImageOption option) const;

    int imageCount() const;
    int currentImageNumber() const;
    QRect currentImageRect() const;
    bool jumpToImage(int imageNumber);
    bool jumpToNextImage();
    int loopCount() const;
    int nextImageDelay() const;

private:
    bool ensureScanned() const;

private:
    enum ScanState {
        ScanError = -1,
        ScanNotScanned = 0,
        ScanSuccess = 1,
    };

    bool m_lossless;
    int m_quality;
    mutable ScanState m_scanState;
    int m_flags;
    int m_width;
    int m_height;
    int m_loop;
    int m_frameCount;
    bool m_hasFirstFrameRead;
    QByteArray m_rawData;
    WebPData m_webpData;
    WebPIterator m_iter;
    WebPDemuxer *m_demuxer;
};

#endif // WEBPHANDLER_H
