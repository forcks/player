#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>

class AppEngine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList listAudio MEMBER audioModel NOTIFY getListAudioName)
    QStringList audioModel;
public:
    AppEngine();
signals:
    void getListAudioName();
public slots:
    void playAudio(QString pathToAudio);
    void showAllAudio(QString getpathToAudio);
};

#endif // APPENGINE_H
