#include "help.h"
#include <QPixmap>
#include <QPainter>

Help::Help(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1000,1000);
    StartModeImg[0]="D:/tpchris1/programming/2017_finalproject/final_1/Image/menu.png";
    StartModeImg[1]="D:/tpchris1/programming/2017_finalproject/final_1/Image/menu_touch.png";
    Instruction[0]="D:/tpchris1/programming/2017_finalproject/final_1/Image/normalmode.png";
    Instruction[1]="D:/tpchris1/programming/2017_finalproject/final_1/Image/vsmode.png";
    Instruction[2]="D:/tpchris1/programming/2017_finalproject/final_1/Image/1Pcontrol.png";
    Instruction[3]="D:/tpchris1/programming/2017_finalproject/final_1/Image/2Pcontrol.png";
    startmode=0;
    pos_x1=1200;
    pos_x2=1700;
    pos_x3=2200;
    pos_x4=2700;
    s_pos_x=1200;
}

void Help::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    pix.load(StartModeImg[startmode]);
    painter.drawPixmap(s_pos_x,650,200,60,pix);
    pix.load(Instruction[0]);
    painter.drawPixmap(pos_x1,250,660,90,pix);
    pix.load(Instruction[1]);
    painter.drawPixmap(pos_x2,350,660,90,pix);
    pix.load(Instruction[2]);
    painter.drawPixmap(pos_x3,450,660,90,pix);
    pix.load(Instruction[3]);
    painter.drawPixmap(pos_x4,550,660,90,pix);

}
