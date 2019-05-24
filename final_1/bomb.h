#ifndef BOMB_H
#define BOMB_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>
class Bomb : public QWidget
{
    Q_OBJECT
public:
    explicit Bomb(QWidget *parent = 0);

    int bombinterval;
    int mode;   //0可用 1放置中 2引爆
    int bombPic;
    int bombrange;
    QTimer *bombTimer;
    int cur_x,cur_y;
    int leftrange,rightrange,uprange,downrange;
protected:
    void paintEvent(QPaintEvent *);
private:
    QString bombImg[4];
    QString explosionImg[10];
private slots:
    void BombAction();
};

#endif // BOMB_H
