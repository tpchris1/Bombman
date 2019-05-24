#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>
class Player : public QWidget
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = 0);
    int mode;   //0 AI 1 玩家
    void SetDirection(int dir);

    int direct;//0向下,1向上,2向左,3向右
    int onestepstop;
    int playerPic;//紀錄圖片編號
    int moveinterval;
    int stepLength;
    int LeaveBomb[5];
protected:
    void paintEvent(QPaintEvent *);
private:
     QString playerImg[48];
     QString map[20][20];

};

#endif // PLAYER_H
