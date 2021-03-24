#include "appengine.h"

#include <QMediaPlayer>
#include <QDir>
#include <QUrl>
#include <QFileInfo>



AppEngine::AppEngine()
{

}

void AppEngine::playAudio(QString pathToAudio){


    /*
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(pathToAudio)));
    player->setVolume(100);
    player->play();
    */
}

void AppEngine::showAllAudio(QString getpathToAudio){
    QDir audioDirectory(getpathToAudio);
    QStringList filters;
    filters << "*.mp3";
    auto audioInfo = audioDirectory.entryInfoList(filters, QDir::Files|QDir::NoDotAndDotDot);

    QStringList listAudio;
    for(int i = 0;i<audioInfo.length();i++){
        int maxSymbol = 60;
        QString nameFile = audioInfo[i].fileName();
        if (audioInfo[i].fileName().length() >maxSymbol){
            nameFile.remove(maxSymbol,audioInfo[i].fileName().length()-(audioInfo[i].fileName().length() - (maxSymbol+3)));
            nameFile+="...";
        }
        listAudio.append(nameFile);
    }

    audioModel = listAudio;
    getListAudioName();
}










