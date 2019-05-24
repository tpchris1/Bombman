#include "easymusic.h"
#include <stdlib.h>
easyMusic::easyMusic(char *path, int volume, int isLoop)
{
   media = new QMediaPlayer;
#ifdef Q_OS_MACOS
    CFURLRef url = (CFURLRef)CFAutorelease((CFURLRef)CFBundleCopyBundleURL(CFBundleGetMainBundle()));
    QString apppath = QUrl::fromCFURL(url).path();
    qDebug() << "App Bundle Path:" << apppath;
    QDir appdir = QDir(apppath);
    appdir.cdUp();
    qDebug() << "App Dir:" << appdir.path();
    media->setMedia(QUrl::fromLocalFile(appdir.filePath(path)));
#else
    media->setMedia(QUrl::fromLocalFile(QFileInfo(path).absoluteFilePath()));
#endif
    media->setVolume(volume);
    isConnectBefore=0;
    if(isLoop){
        setPlayInLoop();
        isConnectBefore=1;
    }
}
easyMusic::~easyMusic()
{

}
void easyMusic::setPlayOneTime(){
    disconnect( media, SIGNAL(stateChanged(QMediaPlayer::State)), media, SLOT(play()));
}
void easyMusic::setPlayInLoop(){
    connect( media, SIGNAL(stateChanged(QMediaPlayer::State)), media, SLOT(play()));
}
void easyMusic::stop(){

    isConnectBefore = disconnect( media, SIGNAL(stateChanged(QMediaPlayer::State)), media, SLOT(play()));
    media->stop();
}
void easyMusic::pause(){
    isConnectBefore = disconnect( media, SIGNAL(stateChanged(QMediaPlayer::State)), media, SLOT(play()));
    media->pause();
}
void easyMusic::play(){
    if(isConnectBefore)
        setPlayInLoop();
    else
        setPlayOneTime();
    media->play();
}
void easyMusic::setVolume(int V){
    media->setVolume(V);
}
void easyMusic::setMusicPath(char *p){
    media->setMedia(QUrl::fromLocalFile(p));
}
void easyMusic::mute(bool m){
    media->setMuted(m);
}
void easyMusic::louderOrlower(bool L){
    if(L==true)
        media->setVolume(media->volume()+10);
    else
        media->setVolume(media->volume()-10);

}
