#include <QDebug>
#include <QDir>

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QUrl>

#include <QProcess>

#include "audiowork.h"

QMediaPlayer *player = new QMediaPlayer;
bool isPause;
QStringList audiolist;
QString nowAudio;

AudioWork::AudioWork(QObject *parent) : QObject(parent)
{
    isPause = false;

    QFile pathToAudioFolder(QDir::currentPath()+"/pathToAudio.txt");

    qDebug()<<pathToAudioFolder.exists();
    QString _pathToAudioFolder;



    if(pathToAudioFolder.open(QIODevice::ReadOnly)){
        QByteArray path = pathToAudioFolder.readAll();
        _pathToAudioFolder = QString::fromUtf8(path);
        _pathToAudioFolder.remove("\n");
        qDebug()<<_pathToAudioFolder;
    }
    pathToAudioFolder.close();

    showAudio(_pathToAudioFolder);
}

QVector<AudioItem> AudioWork::items() const
{
    return mItems;
}

bool AudioWork::setItemAt(int index, const AudioItem &item)
{
    if(index < 0 || index >= mItems.size())
        return false;

    const AudioItem &oldItem = mItems.at(index);
    if(item.nameAudio == oldItem.nameAudio && item.pathToAudio == oldItem.pathToAudio)
        return false;

    mItems[index] = item;
    return true;

}

QFileInfoList AudioWork::scanAudio(QString pathToAudio)
{
    QStringList audioFiles;
    QDir audioFolder(pathToAudio);
    audioFolder.setFilter(QDir::NoFilter);
    audioFolder.setNameFilters(QStringList()<<"*.mp3");
    QFileInfoList list = audioFolder.entryInfoList();

    return list;
}

bool AudioWork::checkFilePathAudio()
{
    QFile pathToAudioFolder(QDir::currentPath()+"/pathToAudio.txt");
    if(pathToAudioFolder.exists())
        return true;
    else
        return false;
}

void AudioWork::showAudio(QString path)
{
    AudioList = scanAudio(path);
    for(int i = 0;i<AudioList.length();i++){
        QString nameFile = AudioList[i].baseName().toUtf8();

        const int maxSymbol = 25;
        const int nameLength = nameFile.length();
        if (nameLength >maxSymbol){
            nameFile = nameFile.remove(maxSymbol,nameLength - maxSymbol);
            nameFile +="...";
        }

        QString pathToFile = AudioList[i].filePath().toUtf8();

        AudioItem item;
        item.nameAudio = nameFile;
        item.pathToAudio = pathToFile;

        mItems.append(item);
        audiolist.append(pathToFile);
    }
}

void AudioWork::playAudio(QString pathToAudio)
{
    //QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(pathToAudio)));

    connect(player, &QMediaPlayer::durationChanged, this, [&](qint64 dur) {
        qDebug()<<dur;
        qDebug()<<player->duration();
        changeDurationAudioSlider(dur);
    });

    player->setVolume(50);
    player->play();
    nowAudio = pathToAudio;


}

void AudioWork::pause()
{
    if(!isPause){
        player->pause();
        isPause = true;
    }
    else{
        player->play();
        isPause = false;
    }
}

void AudioWork::next()
{
    for(int i = 0;i<audiolist.length();i++){

        if(audiolist[i] == nowAudio){
            if(audiolist.length()<=i+1){
                playAudio(audiolist[0]);

                QStringList splitAudioPath = audiolist[0].split('/');
                changeNameAudio(splitAudioPath[splitAudioPath.length()-1]);

                break;
            }else{
                playAudio(audiolist[i+1]);

                QStringList splitAudioPath = audiolist[i+1].split('/');
                changeNameAudio(splitAudioPath[splitAudioPath.length()-1]);

                break;
            }
        }
    }
}

void AudioWork::previous()
{
    for(int i = 0;i<audiolist.length();i++){

        if(audiolist[i] == nowAudio){
            if(i<=0){
                playAudio(audiolist[audiolist.length()-1]);

                QStringList splitAudioPath = audiolist[audiolist.length()-1].split('/');
                changeNameAudio(splitAudioPath[splitAudioPath.length()-1]);

                break;
            }else{
                playAudio(audiolist[i-1]);

                QStringList splitAudioPath = audiolist[i-1].split('/');
                changeNameAudio(splitAudioPath[splitAudioPath.length()-1]);

                break;
            }
        }
    }
}

void AudioWork::editVolume(int volume)
{
    qDebug()<<"volume changed "+QString::number(volume);
    player->setVolume(volume);
}

void AudioWork::savePathToFolderForAudio(QString Path)
{
    if(Path != "" && Path != " "){
        QFile pathToAudioFolderFile(QDir::currentPath()+"/pathToAudio.txt");
        if(pathToAudioFolderFile.open(QIODevice::WriteOnly)){
            const QByteArray arr = Path.toUtf8();
            pathToAudioFolderFile.write(arr);
        }
        pathToAudioFolderFile.close();

        QProcess process;
        process.startDetached(QDir::currentPath()+"/audioPlayer",QStringList());

    }
}

void AudioWork::signalTimerPositionMusic()
{
    changePositionMusic(player->position());
}
