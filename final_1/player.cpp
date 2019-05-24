#include "player.h"

Player::Player(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(50,65);
    playerImg[0]="D:/tpchris1/programming/2017_finalproject/final_1/Image/front_1.png";
    playerImg[1]="D:/tpchris1/programming/2017_finalproject/final_1/Image/front_2.png";
    playerImg[2]="D:/tpchris1/programming/2017_finalproject/final_1/Image/front_3.png";
    playerImg[3]="D:/tpchris1/programming/2017_finalproject/final_1/Image/front_4.png";
    playerImg[4]="D:/tpchris1/programming/2017_finalproject/final_1/Image/front_5.png";
    playerImg[5]="D:/tpchris1/programming/2017_finalproject/final_1/Image/front_6.png";
    playerImg[6]="D:/tpchris1/programming/2017_finalproject/final_1/Image/back_1.png";
    playerImg[7]="D:/tpchris1/programming/2017_finalproject/final_1/Image/back_2.png";
    playerImg[8]="D:/tpchris1/programming/2017_finalproject/final_1/Image/back_3.png";
    playerImg[9]="D:/tpchris1/programming/2017_finalproject/final_1/Image/back_4.png";
    playerImg[10]="D:/tpchris1/programming/2017_finalproject/final_1/Image/back_5.png";
    playerImg[11]="D:/tpchris1/programming/2017_finalproject/final_1/Image/back_6.png";
    playerImg[12]="D:/tpchris1/programming/2017_finalproject/final_1/Image/left_1.png";
    playerImg[13]="D:/tpchris1/programming/2017_finalproject/final_1/Image/left_2.png";
    playerImg[14]="D:/tpchris1/programming/2017_finalproject/final_1/Image/left_3.png";
    playerImg[15]="D:/tpchris1/programming/2017_finalproject/final_1/Image/left_4.png";
    playerImg[16]="D:/tpchris1/programming/2017_finalproject/final_1/Image/left_5.png";
    playerImg[17]="D:/tpchris1/programming/2017_finalproject/final_1/Image/left_6.png";
    playerImg[18]="D:/tpchris1/programming/2017_finalproject/final_1/Image/right_1.png";
    playerImg[19]="D:/tpchris1/programming/2017_finalproject/final_1/Image/right_2.png";
    playerImg[20]="D:/tpchris1/programming/2017_finalproject/final_1/Image/right_3.png";
    playerImg[21]="D:/tpchris1/programming/2017_finalproject/final_1/Image/right_4.png";
    playerImg[22]="D:/tpchris1/programming/2017_finalproject/final_1/Image/right_5.png";
    playerImg[23]="D:/tpchris1/programming/2017_finalproject/final_1/Image/right_6.png";
    playerImg[24]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_front1.png";
    playerImg[25]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_front2.png";
    playerImg[26]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_front3.png";
    playerImg[27]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_front4.png";
    playerImg[28]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_front5.png";
    playerImg[29]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_front6.png";
    playerImg[30]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_back1.png";
    playerImg[31]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_back2.png";
    playerImg[32]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_back3.png";
    playerImg[33]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_back4.png";
    playerImg[34]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_back5.png";
    playerImg[35]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_back6.png";
    playerImg[36]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_left1.png";
    playerImg[37]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_left2.png";
    playerImg[38]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_left3.png";
    playerImg[39]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_left4.png";
    playerImg[40]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_left5.png";
    playerImg[41]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_left6.png";
    playerImg[42]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_right1.png";
    playerImg[43]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_right2.png";
    playerImg[44]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_right3.png";
    playerImg[45]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_right4.png";
    playerImg[46]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_right5.png";
    playerImg[47]="D:/tpchris1/programming/2017_finalproject/final_1/Image/AI_right6.png";

    playerPic=0;
    moveinterval=0;
    stepLength = 10;
}
void Player::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;

    pix.load(playerImg[playerPic]);
    painter.drawPixmap(0,0,50,65,pix);

}

