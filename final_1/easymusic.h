#ifndef EASYMUSIC_H
#define EASYMUSIC_H
#include <QObject>
#include <QFile>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia>
#include <QUrl>

class easyMusic : public QObject
{

public:
    easyMusic(char *path, int volume=100, int isLoop=0);
    void setPlayOneTime();         /*只撥放一次*/
    void setPlayInLoop();          /*循環播放*/
    void stop();                /*停止*/
    void pause();               /*暫停*/
    void play();                /*暫停後的撥放*/
    void setVolume(int V);      /*設定音量*/
    void louderOrlower(bool L); /*提高或降低音量,true為提高,false為降低*/
    void setMusicPath(char *p); /*設定音樂路徑*/
    void mute(bool m);          /*是否靜音*/
    ~easyMusic();

private:
    QMediaPlayer *media;    
    int isConnectBefore;
};

#endif // EASYMUSIC_H
