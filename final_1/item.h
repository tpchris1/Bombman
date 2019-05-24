#ifndef ITEM_H
#define ITEM_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>
class item : public QWidget
{
    Q_OBJECT
public:
    explicit item(QWidget *parent = 0);
     int cur_x,cur_y;
     int type;   // 0:牆壁 1:可破壞物 2:道具
     int mode;   // 0:隱藏 1:顯示
     int itemPic;    // 0:水球 1:範圍  2:房子
protected:
    void paintEvent(QPaintEvent *);

private:
    QString Pic[18];
};

#endif // ITEM_H
