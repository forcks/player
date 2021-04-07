#ifndef AUDIOWORK_H
#define AUDIOWORK_H

#include <QObject>
#include <QVector>
#include <QDir>

struct AudioItem{
    QString nameAudio;
    QString pathToAudio;
};

class AudioWork : public QObject
{
    Q_OBJECT
public:
    QFileInfoList AudioList;

    explicit AudioWork(QObject *parent = nullptr);

    QVector<AudioItem> items() const;

    bool setItemAt(int index,const AudioItem &item);

    QFileInfoList scanAudio(QString pathToAudio);
    bool checkFilePathAudio();

public slots:
    void showAudio(QString path);
    void playAudio(QString pathToAudio);
    void pause();
    void next();
    void previous();
    void editVolume(int volume);

    void savePathToFolderForAudio(QString Path);
    void signalTimerPositionMusic();

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

    void changeNameAudio(QString nameAudio);
    void changePositionMusic(int position);
    void changeDurationAudioSlider(int max);


private:
    QVector<AudioItem> mItems;

};

#endif // AUDIOWORK_H
