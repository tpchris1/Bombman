#include "bomb.h"
#include <QDebug>
Bomb::Bomb(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1000,1000);
    bombImg[0]="D:/tpchris1/programming/2017_finalproject/final_1/Image/waterbomb1.png";
    bombImg[1]="D:/tpchris1/programming/2017_finalproject/final_1/Image/waterbomb2.png";
    bombImg[2]="D:/tpchris1/programming/2017_finalproject/final_1/Image/waterbomb3.png";
    explosionImg[0]="D:/tpchris1/programming/2017_finalproject/final_1/Image/waterbomb_center.png";
    explosionImg[1]="D:/tpchris1/programming/2017_finalproject/final_1/Image/waterbomb_up.png";
    explosionImg[2]="D:/tpchris1/programming/2017_finalproject/final_1/Image/waterbomb_down.png";
    explosionImg[3]="D:/tpchris1/programming/2017_finalproject/final_1/Image/waterbomb_left.png";
    explosionImg[4]="D:/tpchris1/programming/2017_finalproject/final_1/Image/waterbomb_right.png";
    bombPic = 0;
    bombinterval=0;
    bombrange = 1;
    mode = 0;
    leftrange = rightrange = uprange = downrange = bombrange;
}
void Bomb::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    int pixel = 50;
    if(mode == 2){

        pix.load(explosionImg[0]);
        painter.drawPixmap(cur_x,cur_y,pixel,pixel,pix);
        //上下左右
        for(int i=cur_y-pixel;i>=cur_y - pixel*uprange;i-=pixel){
                pix.load(explosionImg[1]);
                painter.drawPixmap(cur_x,i,pixel,pixel,pix);
        }
        for(int i=cur_y+pixel;i<=cur_y + pixel*downrange;i+=pixel){
                pix.load(explosionImg[2]);
                painter.drawPixmap(cur_x,i,pixel,pixel,pix);
        }
        for(int i=cur_x-pixel;i>=cur_x - pixel*leftrange;i-=pixel){
                pix.load(explosionImg[3]);
                painter.drawPixmap(i,cur_y,pixel,pixel,pix);
        }
        for(int i=cur_x+pixel;i<=cur_x + pixel*rightrange;i+=pixel){
                pix.load(explosionImg[4]);
                painter.drawPixmap(i,cur_y,pixel,pixel,pix);
        }
        mode = 3;
    }
    else if(mode == 1){
        pix.load(bombImg[bombPic]);
        painter.drawPixmap(cur_x,cur_y,pixel,pixel,pix);
    }
}

void Bomb::BombAction(){
    /*
    this->close();
        if(bombinterval < 22 && mode==1){
            bombinterval++;
            bombPic = (bombPic + 1)%3;
        }else if(bombinterval >= 22 && mode==1){

        }


    this->show();


    for(int i=0;i<Bombnum;i++){
        bombs[i]->close();
        if(bombs[i]->bombinterval < 22 && bombs[i]->mode==1){
            bombs[i]->bombinterval++;
            bombs[i]->bombPic = (bombs[i]->bombPic + 1)%3;


            if((bombs[i]->cur_x+50 >= players->pos().x()+50 || bombs[i]->cur_x+100 <= players->pos().x() ) || (bombs[i]->cur_y+50 >= players->pos().y()+65 || bombs[i]->cur_y+100 <= players->pos().y()+15) ){
                players->LeaveBomb[i] = 1;
            }


        }else if(bombs[i]->bombinterval >= 22 && bombs[i]->mode == 1){
            Explosion(bombs[i]);
        }else if(bombs[i]->mode == 3){
            bombs[i]->bombinterval = 0;
            bombs[i]->mode = 0;
            bombs[i]->close();
            bombs[i]->bombTimer->stop();
        }else if(bombs[i]->mode == 0){
            bombs[i]->bombTimer->stop();
        }

        if(bombs[i]->mode!=0)  bombs[i]->show();
    }*/
}
