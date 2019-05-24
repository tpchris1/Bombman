#include "selectmode.h"
#include <QPixmap>
#include <QPainter>

SelectMode::SelectMode(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1000,1000);
    SMImg[0]="D:/tpchris1/programming/2017_finalproject/final_1/Image/right_1.png";
    SMImg[1]="D:/tpchris1/programming/2017_finalproject/final_1/Image/right_2.png";
    SMImg[2]="D:/tpchris1/programming/2017_finalproject/final_1/Image/right_3.png";
    SMImg[3]="D:/tpchris1/programming/2017_finalproject/final_1/Image/right_4.png";
    SMImg[4]="D:/tpchris1/programming/2017_finalproject/final_1/Image/right_5.png";
    SMImg[5]="D:/tpchris1/programming/2017_finalproject/final_1/Image/right_6.png";
    SMImg[6]="D:/tpchris1/programming/2017_finalproject/final_1/Image/bgleft_1.png";
    SMImg[7]="D:/tpchris1/programming/2017_finalproject/final_1/Image/bgleft_2.png";
    SMImg[8]="D:/tpchris1/programming/2017_finalproject/final_1/Image/bgleft_3.png";
    SMImg[9]="D:/tpchris1/programming/2017_finalproject/final_1/Image/bgleft_4.png";
    SMImg[10]="D:/tpchris1/programming/2017_finalproject/final_1/Image/bgleft_5.png";
    SMImg[11]="D:/tpchris1/programming/2017_finalproject/final_1/Image/bgleft_6.png";
    SMImg[12]="D:/tpchris1/programming/2017_finalproject/final_1/Image/1.PNG";
    SMImg[13]="D:/tpchris1/programming/2017_finalproject/final_1/Image/2.PNG";
    SMImg[14]="D:/tpchris1/programming/2017_finalproject/final_1/Image/3.PNG";
    SMImg[15]="D:/tpchris1/programming/2017_finalproject/final_1/Image/4.PNG";
    SMImg[16]="D:/tpchris1/programming/2017_finalproject/final_1/Image/5.PNG";
    SMImg[17]="D:/tpchris1/programming/2017_finalproject/final_1/Image/6.PNG";
    SMImg[18]="D:/tpchris1/programming/2017_finalproject/final_1/Image/7.PNG";
    SMImg[19]="D:/tpchris1/programming/2017_finalproject/final_1/Image/8.PNG";
    SMImg[20]="D:/tpchris1/programming/2017_finalproject/final_1/Image/9.PNG";
    SMImg[21]="D:/tpchris1/programming/2017_finalproject/final_1/Image/10.PNG";
    SMImg[22]="D:/tpchris1/programming/2017_finalproject/final_1/Image/11.PNG";
    StartModeImg[0]="D:/tpchris1/programming/2017_finalproject/final_1/Image/1P.png";
    StartModeImg[1]="D:/tpchris1/programming/2017_finalproject/final_1/Image/1P_touch.png";
    HelpModeImg[0]="D:/tpchris1/programming/2017_finalproject/final_1/Image/help.png";
    HelpModeImg[1]="D:/tpchris1/programming/2017_finalproject/final_1/Image/help_touch.png";
    CreditModeImg[0]="D:/tpchris1/programming/2017_finalproject/final_1/Image/credit.png";
    CreditModeImg[1]="D:/tpchris1/programming/2017_finalproject/final_1/Image/credit_touch.png";
    VsModeImg[0]="D:/tpchris1/programming/2017_finalproject/final_1/Image/2P.png";
    VsModeImg[1]="D:/tpchris1/programming/2017_finalproject/final_1/Image/2P_touch.png";
    mode = 0;
    choose=0;
    SMPic=0;
    SMtimerdata=120;
    pos_x=150;
    i=5;
    pos_y=151;
    j=2;
    SMTimer=new QTimer(this);
    connect(SMTimer,SIGNAL(timeout()),this,SLOT(update()));
    SMTimer->start(SMtimerdata);
}

void SelectMode::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    int PicNum_AI = 0,PicNum_VS = 0,PicNum_HELP = 0,PicNum_CREDIT = 0;


    if(mode == 1){
        PicNum_AI = 1;
    }else if(mode == 2){
        PicNum_VS = 1;
    }else if(mode == 3){
        PicNum_CREDIT = 1;
    }else if(mode == 4){
        PicNum_HELP = 1;
    }

    pix.load(SMImg[SMPic]);
    painter.drawPixmap(pos_x,570,70,80,pix);
    pix.load(StartModeImg[PicNum_AI]);
    painter.drawPixmap(100,250,200,60,pix);
    pix.load(VsModeImg[PicNum_VS]);
    painter.drawPixmap(100,330,200,60,pix);
    pix.load(CreditModeImg[PicNum_CREDIT]);
    painter.drawPixmap(100,410,200,60,pix);
    pix.load(HelpModeImg[PicNum_HELP]);
    painter.drawPixmap(100,490,200,60,pix);
    pix.load("D:/tpchris1/programming/2017_finalproject/final_1/Image/LOGO.PNG");
    painter.drawPixmap(480,pos_y,300,240,pix);

    if(i>0)
        SMPic=(SMPic+1)%6;
    else if(i<0)
        SMPic=6+(SMPic+1)%6;
    else if(pos_x>0&&pos_x<150)
        SMPic=12+(SMPic+1)%11;
    if(pos_x>450){
        pos_x=-100;
        i*=-1;
    }
    else if(pos_x<0){
        pos_x=450;
    }
    else if(pos_x==150&&i<0)
        SMPic=12;
    else if(pos_x>0&&pos_x<150){
        if(SMPic<22){
            i=0;
        }
        else{
            i=5;
        }
    }
    pos_x+=i;
    if(pos_y>150||pos_y<100) j*=-1;
    pos_y+=j;
}
