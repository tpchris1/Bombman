#ifndef MAINWINDOW_Hyt
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QDockWidget>
#include <QTextEdit>
#include <QDebug>
#include <QFile>
#include <iostream>
#include <fstream>
#include <Qvector>
#include <QTextStream>
#include <QIODevice>
#include "easymusic.h"
#include "bomb.h"
#include "item.h"
#include "player.h"
#include "downcounter.h"
#include "selectmode.h"
#include "help.h"
#include "credit.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private slots:
    void player1Action();
    void player2Action();
    void DCAction();
    void HelpAction();
    void Key1Action();
    void Key2Action();

    void Bomb1Action();
    void Bomb2Action();
    void Bomb3Action();
    void Bomb4Action();
    void Bomb5Action();
    void Bomb6Action();
    void Bomb7Action();
    void Bomb8Action();
    void Bomb9Action();
    void Bomb10Action();

private:
    void createPlayer();
    void createPlayer2();
    void createBomb();
    void createItem();
    void createBreak();
    void createBlock();
    void createDC();
    void createHelp();
    void ReadFile();
    void playerMove(int dir);
    void player2Move(int dir);
    void SetBomb(int x,int y);
    void SetBomb2(int x,int y);
    void SetItem(int x,int y,int type);

    void GameReady();
    void GameHelp();
    void GameCredit();
    void GameSelect();
    void GameStart(int mode);
    void GameEnd(int mode);

    int CheckBlock(int x,int y,int target);
    int AreaOverlap(int x,int y,int pos_x,int pos_y);
    int AreaCheck(int x,int y);
    int bombHit(int x,int y);
    void Explosion(Bomb *bomb);
    void DetectBomb(Bomb *bomb);

    int win_width;
    int win_height;
    enum{bombCount = 5,breakCount=100,blockCount=100,itemCount=40};
    enum{ready=0,AI=1,VS=2,end=3,helpmode=4,creditmode=5};

    double playerVX,playerVY,player2VX,player2VY;			// 鳥的速度
    double player_x[3];
    double player_y[3];
    int index_playerX;
    int index_playerY;
    int onestepX,onestepY,P2onestepX,P2onestepY;
    double player1timedata,player2timedata,DCtimedata;
    QFile fin;

    Bomb *bombs[bombCount],*bombs2[bombCount];
    QTimer *playerTimer,*player2Timer,*DCTimer,*HelpTimer;
    double bombtimedata,helptimedata;
    int Bombnum,Bomb2num;

    Player *player1,*player2;

    item *items[itemCount];
    item *breaks[breakCount];
    item *blocks[blockCount];

    DownCounter *DC;

    //gamemode
    int gamemode;
    int mapNum;
    Help *help;
    Credit *credit;
    easyMusic *bgm1,*bgm2,*firstbgm,*winbgm,*losebgm;
    easyMusic *bombfgm,*explosionfgm,*winfgm,*losefgm;

    QChar obj[20][20],obj2[20][20];
    SelectMode *SMs;
    QString bgImg[6];
    int bgPic;
    int key1=0,key1_touch=0,key2=0,key2_touch=0;
    QString endloseImg[50],enddiePic[11];
    int endloseOrder=0;
    int tmpendloseOrder=0;
    int enddieOrder=0;
    int tmpenddieOrder=0;

    bool win=true;
    QString endwinImg[51],endlivePic[8];
    int endwinOrder = 0, tmpendwinOrder = 0;
    int endliveOrder = 0, tmpendliveOrder = 0;
};

#endif // MAINWINDOW_H
