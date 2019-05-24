#include "downcounter.h"

DownCounter::DownCounter(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(125,46);
    src[0] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/font_048.png";
    src[1] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/font_049.png";
    src[2] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/font_050.png";
    src[3] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/font_051.png";
    src[4] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/font_052.png";
    src[5] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/font_053.png";
    src[6] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/font_054.png";
    src[7] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/font_055.png";
    src[8] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/font_056.png";
    src[9] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/font_057.png";
    Sec = 0;
    Start = 0;
}
void DownCounter::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap num;

    if(Start){
        int tmpnum = Sec,tmp,pos = 100;
        if(tmpnum==0){
            num.load(src[0]);
            painter.drawPixmap(100,0,24,44,num);
        }

        while(tmpnum>0){
            tmp = tmpnum % 10;
            tmpnum /= 10;
            num.load(src[tmp]);
            painter.drawPixmap(pos,0,24,44,num);
            pos -= 25;
        }
    }
}
