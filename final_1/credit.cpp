#include "credit.h"
#include <QPixmap>
#include <QPainter>

Credit::Credit(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1000,1000);
    MenuModeImg[0]="D:/tpchris1/programming/2017_finalproject/final_1/Image/menu.png";
    MenuModeImg[1]="D:/tpchris1/programming/2017_finalproject/final_1/Image/menu_touch.png";
    menumode=0;
}

void Credit::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    pix.load(MenuModeImg[menumode]);
    painter.drawPixmap(320,650,200,60,pix);
}
