/*
 *	MIT License
 *
 *	Copyright (c) 2018 Fabio Falsini <falsinsoft@gmail.com>
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */
#pragma once

#include <QStandardPaths>
#include <QtAndroidExtras>
#include <QQmlEngine>

class QAndroidSystem : public QObject
{
    Q_PROPERTY(QString dataLocation READ getDataLocation CONSTANT)
    Q_PROPERTY(QString configLocation READ getConfigLocation CONSTANT)
    Q_PROPERTY(QString downloadLocation READ getDownloadLocation CONSTANT)
    Q_PROPERTY(QString musicLocation READ getMusicLocation CONSTANT)
    Q_PROPERTY(QString moviesLocation READ getMoviesLocation CONSTANT)
    Q_PROPERTY(QString picturesLocation READ getPicturesLocation CONSTANT)
    Q_DISABLE_COPY(QAndroidSystem)
    Q_OBJECT

    QAndroidSystem();

public:
    static QObject* qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine);
    static QAndroidSystem* instance();

    const QString& getDataLocation() const;
    const QString& getConfigLocation() const;
    const QString& getDownloadLocation() const;
    const QString& getMusicLocation() const;
    const QString& getMoviesLocation() const;
    const QString& getPicturesLocation() const;

private:
    static QAndroidSystem *m_pInstance;

    struct {
        QString DataLocation;
        QString ConfigLocation;
        QString DownloadLocation;
        QString MusicLocation;
        QString MoviesLocation;
        QString PicturesLocation;
    } m_StandardPaths;

    void LoadStandardPaths();
};
