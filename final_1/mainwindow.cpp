#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    win_width = 850;
    win_height = 850;
    this->setFixedSize(win_width,win_height);
    this->setWindowIcon(QIcon("D:/tpchris1/programming/2017_finalproject/final_1/Image/LOGO.png"));
    this->setWindowTitle("Final : Bombman");
    ReadFile();
    help = new Help(this);
    credit = new Credit(this);
    SMs = new SelectMode(this);
    for(int i=0;i<bombCount;i++){
        bombs2[i] = new Bomb(this);
        bombs[i] = new Bomb(this);
    }
    for(int i=0;i<itemCount;i++)    items[i] = new item(this);
    for(int i=0;i<breakCount;i++)    breaks[i] = new item(this);
    for(int i=0;i<blockCount;i++)   blocks[i] = new item(this);

    DC = new DownCounter(this);
    player2 = new Player(this);
    player1 = new Player(this);

    GameReady();
}

MainWindow::~MainWindow()
{

}
void MainWindow::ReadFile(){

    bgm1 = new easyMusic("D:/tpchris1/programming/2017_finalproject/final_1/Music/BGM1.wav",80,1);
    bgm2 = new easyMusic("D:/tpchris1/programming/2017_finalproject/final_1/Music/BGM2.wav",80,1);
    firstbgm = new easyMusic("D:/tpchris1/programming/2017_finalproject/final_1/Music/FirstBGM.wav",80,1);
    winbgm =  new easyMusic("D:/tpchris1/programming/2017_finalproject/final_1/Music/WinBGM.wav",80,1);
    losebgm =  new easyMusic("D:/tpchris1/programming/2017_finalproject/final_1/Music/LoseBGM.wav",80,1);
    bombfgm =  new easyMusic("D:/tpchris1/programming/2017_finalproject/final_1/Music/bombFGM.wav",85,0);
    explosionfgm =  new easyMusic("D:/tpchris1/programming/2017_finalproject/final_1/Music/explosionFGM.wav",85,0);
    winfgm =  new easyMusic("D:/tpchris1/programming/2017_finalproject/final_1/Music/victory.wav",85,0);
    losefgm =  new easyMusic("D:/tpchris1/programming/2017_finalproject/final_1/Music/defeat.wav",85,0);


    QFile fin(":/map/obj1.txt");
    if(fin.open(QIODevice::ReadOnly)){
        QTextStream in(&fin);
        for(int obji=0;obji<16;obji++){
            QString line = in.readLine();

            for(int objj=0;objj<16;objj++){
                obj[obji][objj] = line[objj];
            }
        }
    }
    QFile fin2(":/map/obj2.txt");
    if(fin2.open(QIODevice::ReadOnly)){
        QTextStream in2(&fin2);
        for(int obji=0;obji<16;obji++){
            QString line = in2.readLine();

            for(int objj=0;objj<16;objj++){
                obj2[obji][objj] = line[objj];
            }
        }
    }


    bgImg[0]="D:/tpchris1/programming/2017_finalproject/final_1/Image/bg3.jpg";
    bgImg[1]="D:/tpchris1/programming/2017_finalproject/final_1/Image/map1.png";
    bgImg[2]="D:/tpchris1/programming/2017_finalproject/final_1/Image/bg_help.png";
    bgImg[3]="D:/tpchris1/programming/2017_finalproject/final_1/Image/finaltry.png";
    bgImg[4]="D:/tpchris1/programming/2017_finalproject/final_1/Image/map2.png";
    bgImg[5]="D:/tpchris1/programming/2017_finalproject/final_1/Image/back1.png";
    endloseImg[0]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg1.png";
    endloseImg[1]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg2.png";
    endloseImg[2]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg3.png";
    endloseImg[3]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg4.png";
    endloseImg[4]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg5.png";
    endloseImg[5]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg6.png";
    endloseImg[6]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg7.png";
    endloseImg[7]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg8.png";
    endloseImg[8]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg9.png";
    endloseImg[9]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg10.png";
    endloseImg[10]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg11.png";
    endloseImg[11]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg12.png";
    endloseImg[12]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg13.png";
    endloseImg[13]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg14.png";
    endloseImg[14]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg15.png";
    endloseImg[15]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg16.png";
    endloseImg[16]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg17.png";
    endloseImg[17]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg18.png";
    endloseImg[18]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg19.png";
    endloseImg[19]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg20.png";
    endloseImg[20]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg21.png";
    endloseImg[21]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg22.png";
    endloseImg[22]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg23.png";
    endloseImg[23]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg24.png";
    endloseImg[24]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg25.png";
    endloseImg[25]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg26.png";
    endloseImg[26]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg27.png";
    endloseImg[27]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg28.png";
    endloseImg[28]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg29.png";
    endloseImg[29]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg30.png";
    endloseImg[30]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg31.png";
    endloseImg[31]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg32.png";
    endloseImg[32]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg33.png";
    endloseImg[33]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg34.png";
    endloseImg[34]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg35.png";
    endloseImg[35]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg36.png";
    endloseImg[36]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg37.png";
    endloseImg[37]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg38.png";
    endloseImg[38]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg39.png";
    endloseImg[39]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg40.png";
    endloseImg[40]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg41.png";
    endloseImg[41]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg42.png";
    endloseImg[42]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg43.png";
    endloseImg[43]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg44.png";
    endloseImg[44]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg45.png";
    endloseImg[45]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg46.png";
    endloseImg[46]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg47.png";
    endloseImg[47]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg48.png";
    endloseImg[48]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg49.png";
    endloseImg[49]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/failimg/failimg50.png";
    enddiePic[0]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/diepic/diepic1.png";
    enddiePic[1]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/diepic/diepic2.png";
    enddiePic[2]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/diepic/diepic3.png";
    enddiePic[3]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/diepic/diepic4.png";
    enddiePic[4]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/diepic/diepic5.png";
    enddiePic[5]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/diepic/diepic6.png";
    enddiePic[6]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/diepic/diepic7.png";
    enddiePic[7]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/diepic/diepic8.png";
    enddiePic[8]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/diepic/diepic9.png";
    enddiePic[9]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/diepic/diepic10.png";
    enddiePic[10]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/diepic/diepic11.png";
    endwinImg[0]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg1.png";
    endwinImg[1]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg2.png";
    endwinImg[2]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg3.png";
    endwinImg[3]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg4.png";
    endwinImg[4]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg5.png";
    endwinImg[5]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg6.png";
    endwinImg[6]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg7.png";
    endwinImg[7]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg8.png";
    endwinImg[8]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg9.png";
    endwinImg[9]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg10.png";
    endwinImg[10]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg11.png";
    endwinImg[11]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg12.png";
    endwinImg[12]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg13.png";
    endwinImg[13]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg14.png";
    endwinImg[14]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg15.png";
    endwinImg[15]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg16.png";
    endwinImg[16]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg17.png";
    endwinImg[17]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg18.png";
    endwinImg[18]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg19.png";
    endwinImg[19]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg20.png";
    endwinImg[20]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg21.png";
    endwinImg[21]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg22.png";
    endwinImg[22]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg23.png";
    endwinImg[23]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg24.png";
    endwinImg[24]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg25.png";
    endwinImg[25]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg26.png";
    endwinImg[26]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg27.png";
    endwinImg[27]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg28.png";
    endwinImg[28]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg29.png";
    endwinImg[29]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg30.png";
    endwinImg[30]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg31.png";
    endwinImg[31]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg32.png";
    endwinImg[32]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg33.png";
    endwinImg[33]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg34.png";
    endwinImg[34]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg35.png";
    endwinImg[35]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg36.png";
    endwinImg[36]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg37.png";
    endwinImg[37]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg38.png";
    endwinImg[38]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg39.png";
    endwinImg[39]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg40.png";
    endwinImg[40]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg41.png";
    endwinImg[41]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg42.png";
    endwinImg[42]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg43.png";
    endwinImg[43]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg44.png";
    endwinImg[44]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg45.png";
    endwinImg[45]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg46.png";
    endwinImg[46]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg47.png";
    endwinImg[47]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg48.png";
    endwinImg[48]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg49.png";
    endwinImg[49]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg50.png";
    endwinImg[50]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/winimg/winimg51.png";
    endlivePic[0]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/livepic/livepic1.png";
    endlivePic[1]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/livepic/livepic2.png";
    endlivePic[2]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/livepic/livepic3.png";
    endlivePic[3]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/livepic/livepic4.png";
    endlivePic[4]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/livepic/livepic5.png";
    endlivePic[5]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/livepic/livepic6.png";
    endlivePic[6]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/livepic/livepic7.png";
    endlivePic[7]="D:/tpchris1/programming/2017_finalproject/final_1/Pic/livepic/livepic8.png";
}
void MainWindow::mousePressEvent(QMouseEvent *event){
    if(gamemode==ready){
        if(event->button()==Qt::LeftButton){
             // 0: menu  1:AI 2:VS 3:credit 4:help
            qDebug() <<SMs->mode;
             if(event->pos().x()>100&&event->pos().x()<300&&event->pos().y()>250&&event->pos().y()<310){
                 if(SMs->mode==0)
                     SMs->choose=0;
                 SMs->mode=1;
             }
             else if(event->pos().x()>100&&event->pos().x()<300&&event->pos().y()>330&&event->pos().y()<390){
                 if(SMs->mode==0)
                     SMs->choose=0;
                 SMs->mode=2;
             }
             else if(event->pos().x()>100&&event->pos().x()<300&&event->pos().y()>410&&event->pos().y()<470){
                 if(SMs->mode==0)
                     SMs->choose=0;
                 SMs->mode=3;
             }
             else if(event->pos().x()>100&&event->pos().x()<300&&event->pos().y()>490&&event->pos().y()<550){
                 if(SMs->mode==0)
                     SMs->choose=0;
                 SMs->mode=4;
             }
             else{
                 SMs->mode=0;
             }
        }
        if(SMs->mode==1){
            if(event->button()==Qt::LeftButton&&SMs->choose){
                GameStart(0);
            }
            SMs->choose=1;
        }
        if(SMs->mode==2){
            if(event->button()==Qt::LeftButton&&SMs->choose){
                GameStart(1);
            }
            SMs->choose=1;
        }
        if(SMs->mode == 3){
            if(event->button()==Qt::LeftButton && SMs->choose){
                GameCredit();
            }
            SMs->choose = 1;
        }
        if(SMs->mode == 4){
            if(event->button()==Qt::LeftButton && SMs->choose){
                GameHelp();
            }
            SMs->choose = 1;
        }


    }
    if(gamemode == helpmode){
        if(event->button()==Qt::LeftButton){
            if(event->pos().x() > 320 && event->pos().x() < 520 && event->pos().y() <710 && event->pos().y() >650){
                if(help->startmode == 0)    help->choose = 0;

                help->startmode = 1;
            }else help->startmode = 0;


        }
        if(help->startmode == 1){
            if(event->button()==Qt::LeftButton && help->choose){
                bgPic = 0;
                HelpTimer->stop();
                GameReady();
            }
            help->choose = 1;
        }
    }
    if(gamemode == creditmode){
        if(event->button()==Qt::LeftButton){
            if(event->pos().x() > 320 && event->pos().x() < 520 && event->pos().y() <710 && event->pos().y() >650){
                if(credit->menumode == 0)    credit->choose = 0;
                credit->close();
                credit->menumode = 1;
                credit->show();
            }else credit->menumode = 0;


        }
        if(credit->menumode == 1){
            if(event->button()==Qt::LeftButton && credit->choose){
                bgPic = 0;
                GameReady();
            }
            credit->choose = 1;
        }
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(gamemode==AI || gamemode == VS)
    {
        if(key1_touch==0){
            if(event->key()==Qt::Key_Up)
            {
                key1_touch=1;
                key1=0x01000013;

            }
            else if(event->key()==Qt::Key_Down)
            {
                key1_touch=1;
                key1=0x01000015;
            }
            else if(event->key()==Qt::Key_Left)
            {
                key1_touch=1;
                key1=0x01000012;
            }
            else if(event->key()==Qt::Key_Right)
            {
                key1_touch=1;
                key1=0x01000014;
            }

        }
        if(key2_touch==0){
            if(event->key()==Qt::Key_W)
            {
                key2_touch=1;
                key2=event->key();
            }
            else if(event->key()==Qt::Key_S)
            {
                key2_touch=1;
                key2=event->key();
            }
            else if(event->key()==Qt::Key_A)
            {
                key2_touch=1;
                key2=event->key();
            }
            else if(event->key()==Qt::Key_D)
            {
                key2_touch=1;
                key2=event->key();
            }

        }

        if(event->key()==Qt::Key_Space){
            SetBomb(player1->pos().x()+25,player1->pos().y()+50);
        }

        if(player2->mode == 1){
            if(event->key()==Qt::Key_Q){
                SetBomb2(player2->pos().x()+25,player2->pos().y()+50);
            }
        }
        if(event->key()==Qt::Key_O){
            GameEnd(0);
        }
        if(event->key()==Qt::Key_P){
            GameEnd(1);
        }

    }
    if(gamemode==end){
        if(event->key()==Qt::Key_Escape){
            GameReady();
        }
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Up||event->key()==Qt::Key_Down||event->key()==Qt::Key_Left||event->key()==Qt::Key_Right){
        key1_touch=0;
        key1=0;
    }
    if(event->key()==Qt::Key_W||event->key()==Qt::Key_S||event->key()==Qt::Key_A||event->key()==Qt::Key_D){
        key2_touch=0;
        key2=0;
    }
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(bgImg[5]);
    painter.drawPixmap(0,0,850,850,pix);
    pix.load(bgImg[bgPic]);
    painter.drawPixmap(50,50, 750, 750, pix);
    if(gamemode==end){
        update();
        pix.load("D:/tpchris1/programming/2017_finalproject/final_1/Pic/fullblack.png");
        painter.drawPixmap(50,50,750,750,pix);

        if(win==false){
            pix.load(endloseImg[endloseOrder]);
            painter.drawPixmap(50,-50,750,400,pix);
            tmpendloseOrder++;
            if(tmpendloseOrder%8==0){
                endloseOrder++;
                endloseOrder%=50;
            }
            pix.load(enddiePic[enddieOrder]);
            painter.drawPixmap(375,400,96,200,pix);
            tmpenddieOrder++;
            tmpenddieOrder%=8;
            if(tmpenddieOrder==0){
                enddieOrder++;
                if(enddieOrder==11){
                    enddieOrder = 9;
                }
            }
        }
        else{
            pix.load(endwinImg[endwinOrder]);
            painter.drawPixmap(50,-50,750,400,pix);
            tmpendwinOrder++;
            if(tmpendwinOrder%8==0){
                endwinOrder++;
                endwinOrder%=51;
            }
            pix.load(endlivePic[endliveOrder]);
            painter.drawPixmap(375,500,96,128,pix);
            tmpendliveOrder++;
            tmpendliveOrder%=8;
            if(tmpendliveOrder==0){
                endliveOrder++;
                endliveOrder%=8;
            }
        }
    }
}

void MainWindow::createPlayer(){

    player_x[0]=0;
    player_x[1]=2;
    player_x[2]=-2;
    player_y[0]=0;
    player_y[1]=2;
    player_y[2]=-2;

    player1->move(50,25);
    player1->close();
    index_playerX=0;
    index_playerY=0;
    onestepX = 50;
    onestepY = 35;
    playerVX=0.0;
    playerVY=0.0;
    playerTimer=new QTimer(this);
    connect(playerTimer,SIGNAL(timeout()),this,SLOT(player1Action()));
    connect(playerTimer,SIGNAL(timeout()),this,SLOT(Key1Action()));

    player1timedata=0.01;
}
void MainWindow::createPlayer2(){
    player2->playerPic=24;
    player2->move(750,735);
    player2->close();
    player2VX=0.0;
    player2VY=0.0;
    P2onestepX=750;
    P2onestepY=745;
    player2Timer=new QTimer(this);
    connect(player2Timer,SIGNAL(timeout()),this,SLOT(player2Action()));
    connect(player2Timer,SIGNAL(timeout()),this,SLOT(Key2Action()));
}
void MainWindow::createItem(){
    for(int i=0;i<itemCount;i++){
        items[i]->cur_x = 1000;
        items[i]->cur_y = 1000;
        items[i]->type = 2;
        items[i]->mode = 0;
        items[i]->itemPic = 0;
        items[i]->close();
    }
}
void MainWindow::createBreak(){
    int length = 0, Create;
    if(SMs->mode == 1){
        for(int obji=1;obji<16;obji++){
            for(int objj=1;objj<16;objj++){
                if(obj[objj][obji]== '0' && (objj > 4 || obji > 4) && (objj < 13 || obji < 13)){

                    Create = rand()%100 + 1;
                    if(Create > 40 && Create < 65 && length < breakCount){
                        breaks[length]->cur_x = obji*50;
                        breaks[length]->cur_y = objj*50;
                        breaks[length]->type = 1;
                        breaks[length]->mode = 0;
                        breaks[length]->itemPic = rand()%3 + 6;
                        breaks[length]->close();
                        length++;
                    }
                }
            }
        }
        for(int i=length;i<breakCount;i++){
            breaks[i]->cur_x = 1000;
            breaks[i]->cur_y = 1000;
            breaks[i]->type = 1;
            breaks[i]->mode = 0;
            breaks[i]->itemPic = 4;
            breaks[i]->close();
        }
    }else if(SMs->mode == 2){
        for(int obji=1;obji<16;obji++){
            for(int objj=1;objj<16;objj++){
                if(obj2[objj][obji]== '0' && (objj > 4 || obji > 4) && (objj < 13 || obji < 13)){
                    Create = rand()%100 + 1;
                    if(Create > 40 && Create < 65 && length < breakCount){
                        breaks[length]->cur_x = obji*50;
                        breaks[length]->cur_y = objj*50;
                        breaks[length]->type = 1;
                        breaks[length]->mode = 0;
                        breaks[length]->itemPic = rand()% 2+ 14;
                        breaks[length]->close();
                        length++;
                    }
                }
            }
        }
        for(int i=length;i<breakCount;i++){
            breaks[i]->cur_x = 1000;
            breaks[i]->cur_y = 1000;
            breaks[i]->type = 1;
            breaks[i]->mode = 0;
            breaks[i]->itemPic = 14;
            breaks[i]->close();
        }
    }

}
void MainWindow::createBlock(){
    int length = 0;
    if(SMs->mode == 1){
        for(int obji=0;obji<16;obji++){
            for(int objj=0;objj<16;objj++){
                if(length < blockCount && obj[objj][obji]!='0'){
                    blocks[length]->cur_x = obji*50;
                    blocks[length]->cur_y = objj*50;
                    blocks[length]->type = 0;
                    blocks[length]->mode = 0;
                    blocks[length]->close();
                    if(obj[objj][obji]=='1')                    blocks[length]->itemPic = 3;
                    else if(obj[objj][obji]=='2')               blocks[length]->itemPic = 4;
                    else if(obj[objj][obji]=='3')               blocks[length]->itemPic = 5;

                    length++;
                }
            }
        }
        for(int i=length;i<blockCount;i++){
            blocks[i]->cur_x = 1000;
            blocks[i]->cur_y = 1000;
            blocks[i]->type = 0;
            blocks[i]->mode = 0;
            blocks[i]->itemPic = 3;
            blocks[i]->close();
        }
    }
    else if(SMs->mode == 2){
        for(int obji=0;obji<16;obji++){
            for(int objj=0;objj<16;objj++){
               if(length < blockCount && obj2[objj][obji]!='0'){
                    blocks[length]->cur_x = obji*50;
                    blocks[length]->cur_y = objj*50;
                    blocks[length]->type = 0;
                    blocks[length]->mode = 0;
                    blocks[length]->close();
                    if(obj2[objj][obji]=='1')                   blocks[length]->itemPic = 10;
                    else if(obj2[objj][obji]=='2')              blocks[length]->itemPic = 13;
                    else if(obj2[objj][obji]=='3')              blocks[length]->itemPic = 11;
                    else if(obj2[objj][obji]=='4')              blocks[length]->itemPic = 12;

                    length++;
                }

            }
        }
        for(int i=length;i<blockCount;i++){
            blocks[i]->cur_x = 1000;
            blocks[i]->cur_y = 1000;
            blocks[i]->type = 0;
            blocks[i]->mode = 0;
            blocks[i]->itemPic = 3;
            blocks[i]->close();
        }
    }
}
void MainWindow::createBomb()
{
   for(int i=0;i<bombCount;i++){
        bombs[i]->move(50,50);
        bombs[i]->close();
        bombs[i]->bombinterval = 0;
        bombs[i]->bombrange = 1;
        bombs[i]->mode = 0;
        bombs[i]->bombTimer = new QTimer(this);

        bombs2[i]->move(50,50);
        bombs2[i]->close();
        bombs2[i]->bombinterval = 0;
        bombs2[i]->bombrange = 1;
        bombs2[i]->mode = 0;
        bombs2[i]->bombTimer = new QTimer(this);

        bombtimedata = 150;
   }
   connect(bombs[0]->bombTimer,SIGNAL(timeout()),this,SLOT(Bomb1Action()));
   connect(bombs[1]->bombTimer,SIGNAL(timeout()),this,SLOT(Bomb2Action()));
   connect(bombs[2]->bombTimer,SIGNAL(timeout()),this,SLOT(Bomb3Action()));
   connect(bombs[3]->bombTimer,SIGNAL(timeout()),this,SLOT(Bomb4Action()));
   connect(bombs[4]->bombTimer,SIGNAL(timeout()),this,SLOT(Bomb5Action()));
   connect(bombs2[0]->bombTimer,SIGNAL(timeout()),this,SLOT(Bomb6Action()));
   connect(bombs2[1]->bombTimer,SIGNAL(timeout()),this,SLOT(Bomb7Action()));
   connect(bombs2[2]->bombTimer,SIGNAL(timeout()),this,SLOT(Bomb8Action()));
   connect(bombs2[3]->bombTimer,SIGNAL(timeout()),this,SLOT(Bomb9Action()));
   connect(bombs2[4]->bombTimer,SIGNAL(timeout()),this,SLOT(Bomb10Action()));
}
void MainWindow::createDC(){
    DC->move(650,0);
    DC->close();
    DC->Sec = 1000;
    DC->Start = 0;
    DCTimer = new QTimer(this);
    connect( DCTimer,SIGNAL(timeout()),this,SLOT(DCAction()));
    DCtimedata = 300;
}
void MainWindow::createHelp(){
    help->close();
    help->pos_x1 = 1200;
    help->pos_x2 = 1700;
    help->pos_x3 = 2200;
    help->pos_x4 = 2700;
    help->s_pos_x = 1200;
    HelpTimer = new QTimer(this);
    connect(HelpTimer,SIGNAL(timeout()),this,SLOT(HelpAction()));
    helptimedata = 0.000001;
}
void MainWindow::player1Action(){
    player1->moveinterval++;
        if(player1->moveinterval==player1->stepLength){
            player1->moveinterval=0;
            switch(player1->direct){
                case 0:
                    if(!player1->onestepstop)    player1->playerPic=(player1->playerPic+1)%6;
                    else    player1->playerPic=0;
                break;
                case 1:
                    if(!player1->onestepstop)    player1->playerPic=(player1->playerPic+1)%6+6;
                    else    player1->playerPic=6;
                break;
                case 2:
                    if(!player1->onestepstop)    player1->playerPic=(player1->playerPic+1)%6+12;
                    else    player1->playerPic=12;
                break;
                case 3:
                    if(!player1->onestepstop)    player1->playerPic=(player1->playerPic+1)%6+18;
                    else    player1->playerPic=18;
                break;
            }
        }

        player2->moveinterval++;
            if(player2->moveinterval==player2->stepLength){
                player2->moveinterval=0;
                switch(player2->direct){
                    case 0:
                        if(!player2->onestepstop)    player2->playerPic=(player2->playerPic+1)%6+24;
                        else    player2->playerPic=24;
                    break;
                    case 1:
                        if(!player2->onestepstop)    player2->playerPic=(player2->playerPic+1)%6+30;
                        else    player2->playerPic=30;
                    break;
                    case 2:
                        if(!player2->onestepstop)    player2->playerPic=(player2->playerPic+1)%6+36;
                        else    player2->playerPic=36;
                    break;
                    case 3:
                        if(!player2->onestepstop)    player2->playerPic=(player2->playerPic+1)%6+42;
                        else    player2->playerPic=42;
                    break;
                }
            }

    player1->move(player1->pos().x()+playerVX,player1->pos().y()+playerVY);
    if(player1->direct==0&&player1->pos().y()>=onestepY){
        player1->move(player1->pos().x(),onestepY);
        player1->onestepstop=1;
    }
    if(player1->direct==1&&player1->pos().y()<=onestepY){
        player1->move(player1->pos().x(),onestepY);
        player1->onestepstop=1;
    }
    if(player1->direct==2&&player1->pos().x()<=onestepX){
        player1->move(onestepX,player1->pos().y());
        player1->onestepstop=1;
    }
    if(player1->direct==3&&player1->pos().x()>=onestepX){
        player1->move(onestepX,player1->pos().y());
        player1->onestepstop=1;
    }
    if(player1->pos().x()<=50){
        player1->move(50,player1->pos().y());
        if(player1->playerPic >= 12 && player1->playerPic <18)
            player1->onestepstop = 1;

    }
    if(player1->pos().x()>=750){
        player1->move(750,player1->pos().y());
        if(player1->playerPic >= 18 && player1->playerPic<24)
            player1->onestepstop = 1;
    }
    if(player1->pos().y()<=25){
        player1->move(player1->pos().x(),25);
        if(player1->playerPic >= 6  && player1->playerPic <12)
            player1->onestepstop = 1;
    }
    if(player1->pos().y()>=735){
        player1->move(player1->pos().x(),735);
        if(player1->playerPic < 6)
            player1->onestepstop = 1;
    }

    player2->move(player2->pos().x()+player2VX,player2->pos().y()+player2VY);
    if(player2->direct==0&&player2->pos().y()>=P2onestepY){
        player2->move(player2->pos().x(),P2onestepY);
        player2->onestepstop=1;
    }
    if(player2->direct==1&&player2->pos().y()<=P2onestepY){
        player2->move(player2->pos().x(),P2onestepY);
        player2->onestepstop=1;
    }
    if(player2->direct==2&&player2->pos().x()<=P2onestepX){
        player2->move(P2onestepX,player2->pos().y());
        player2->onestepstop=1;
    }
    if(player2->direct==3&&player2->pos().x()>=P2onestepX){
        player2->move(P2onestepX,player2->pos().y());
        player2->onestepstop=1;
    }
    if(player2->pos().x()<=50){
        player2->move(50,player2->pos().y());
        if(player2->playerPic >= 36 && player2->playerPic <42)
            player2->onestepstop = 1;

    }
    if(player2->pos().x()>=750){
        player2->move(750,player2->pos().y());
        if(player2->playerPic >= 42)
            player2->onestepstop = 1;
    }
    if(player2->pos().y()<=25){
        player2->move(player2->pos().x(),25);
        if(player2->playerPic >= 30  && player2->playerPic <36)
            player1->onestepstop = 1;
    }
    if(player2->pos().y()>=735){
        player2->move(player2->pos().x(),735);
        if(player2->playerPic>=24 && player2->playerPic < 30)
            player2->onestepstop = 1;
    }
}
void MainWindow::player2Action(){

    player2->moveinterval++;
    if(player2->moveinterval==player2->stepLength){
        player2->moveinterval=0;
        switch(player2->direct){
            case 0:
                if(!player2->onestepstop)    player2->playerPic=(player2->playerPic+1)%6+24;
                else    player2->playerPic=24;
            break;
            case 1:
                if(!player2->onestepstop)    player2->playerPic=(player2->playerPic+1)%6+30;
                else    player2->playerPic=30;
            break;
            case 2:
                if(!player2->onestepstop)    player2->playerPic=(player2->playerPic+1)%6+36;
                else    player2->playerPic=36;
            break;
            case 3:
                if(!player2->onestepstop)    player2->playerPic=(player2->playerPic+1)%6+42;
                else    player2->playerPic=42;
            break;
        }
    }

    player2->move(player2->pos().x()+player2VX,player2->pos().y()+player2VY);
    if(player2->direct==0&&player2->pos().y()>=P2onestepY){
        player2->move(player2->pos().x(),P2onestepY);
        player2->onestepstop=1;
    }
    if(player2->direct==1&&player2->pos().y()<=P2onestepY){
        player2->move(player2->pos().x(),P2onestepY);
        player2->onestepstop=1;
    }
    if(player2->direct==2&&player2->pos().x()<=P2onestepX){
        player2->move(P2onestepX,player2->pos().y());
        player2->onestepstop=1;
    }
    if(player2->direct==3&&player2->pos().x()>=P2onestepX){
        player2->move(P2onestepX,player2->pos().y());
        player2->onestepstop=1;
    }
    if(player2->pos().x()<=50){
        player2->move(50,player2->pos().y());
        if(player2->playerPic >= 36 && player2->playerPic <42)
            player2->onestepstop = 1;

    }
    if(player2->pos().x()>=750){
        player2->move(750,player2->pos().y());
        if(player2->playerPic >= 42)
            player2->onestepstop = 1;
    }
    if(player2->pos().y()<=25){
        player2->move(player2->pos().x(),25);
        if(player2->playerPic >= 30  && player2->playerPic <36)
            player2->onestepstop = 1;
    }
    if(player2->pos().y()>=735){
        player2->move(player2->pos().x(),735);
        if(player2->playerPic>=24 && player2->playerPic < 30)
            player2->onestepstop = 1;
    }
}
void MainWindow::DCAction(){
    if(DC->Sec==0){
        GameEnd(0);
        DC->Start = 0;
    }
    if(DC->Start == 1){
        DC->close();
        DC->Sec--;
        DC->show();
    }
}
void MainWindow::HelpAction(){
    help->close();
    if(help->pos_x1 > 100) help->pos_x1-=20;
    if(help->pos_x2 > 100) help->pos_x2-=20;
    if(help->pos_x3 > 100) help->pos_x3-=20;
    if(help->pos_x4 > 100) help->pos_x4-=20;
    if(help->pos_x4 <=100){
        help->s_pos_x = 320;
    }
    help->show();
}
void MainWindow::Key1Action(){
    if(key1_touch==1){
        switch(key1)
        {
        case 0:
            break;
        case 0x01000012: //Qt::Key_left
             if(CheckBlock(player1->pos().x() - 10,player1->pos().y(),1))  playerMove(2);
            break;
        case 0x01000013: //Qt::Key_Up
             if(CheckBlock(player1->pos().x(),player1->pos().y() - 10,1))  playerMove(0);
            break;
        case 0x01000014: //Qt::Key_Right
             if(CheckBlock(player1->pos().x() + 10,player1->pos().y(),1))  playerMove(3);
            break;
        case 0x01000015: //Qt::Key_Down
             if(CheckBlock(player1->pos().x(),player1->pos().y() + 10,1))  playerMove(1);
            break;
        default:
            break;
        }
    }
}
void MainWindow::Key2Action(){
    if(key2_touch == 1 && player2->mode == 1){
        switch(key2)
        {
        case 0x41: //Qt::Key_A
             if(CheckBlock(player2->pos().x() - 10,player2->pos().y(),2))  player2Move(2);
            break;
        case 0x57: //Qt::Key_W
             if(CheckBlock(player2->pos().x(),player2->pos().y() - 10,2))  player2Move(0);
            break;
        case 0x44: //Qt::Key_D
             if(CheckBlock(player2->pos().x() + 10,player2->pos().y(),2))  player2Move(3);
            break;
        case 0x53: //Qt::Key_S
             if(CheckBlock(player2->pos().x(),player2->pos().y() + 10,2))  player2Move(1);
            break;
        default:
            break;
        }
    }
    if(player2->mode==0){
        double interval_x=player2->pos().x()-player1->pos().x();
        double interval_y=player2->pos().y()-player1->pos().y();

        if(interval_x > -20 && interval_x < 20 && interval_y > -20 && interval_y < 20 ){
            GameEnd(0);
        }

        if(interval_x>0&&interval_y>0&&interval_x>interval_y){
            if(CheckBlock(player2->pos().x() - 10,player2->pos().y(),2))  player2Move(2);
            else{
                if(CheckBlock(player2->pos().x(),player2->pos().y() - 10,2))  player2Move(0);
                else{
                   if(CheckBlock(player2->pos().x(),player2->pos().y() + 10,2))  player2Move(1);
                   else{
                       if(CheckBlock(player2->pos().x() + 10,player2->pos().y(),2))  player2Move(3);
                   }
                }
            }
        }
        else if(interval_x>0&&interval_y>0&&interval_x<interval_y){
            if(CheckBlock(player2->pos().x(),player2->pos().y() - 10,2))  player2Move(0);
            else{
                if(CheckBlock(player2->pos().x() - 10,player2->pos().y(),2))  player2Move(2);
                else{
                   if(CheckBlock(player2->pos().x(),player2->pos().y() + 10,2))  player2Move(1);
                   else{
                       if(CheckBlock(player2->pos().x() + 10,player2->pos().y(),2))  player2Move(3);
                   }
                }
            }
        }
        else if(interval_x<0&&interval_y>0&&-interval_x>interval_y){
            if(CheckBlock(player2->pos().x() + 10,player2->pos().y(),2))  player2Move(3);
            else{
                if(CheckBlock(player2->pos().x(),player2->pos().y() - 10,2))  player2Move(0);
                else{
                   if(CheckBlock(player2->pos().x(),player2->pos().y() + 10,2))  player2Move(1);
                   else{
                       if(CheckBlock(player2->pos().x() - 10,player2->pos().y(),2))  player2Move(2);
                   }
                }
            }
        }
        else if(interval_x<0&&interval_y>0&&-interval_x<interval_y){
            if(CheckBlock(player2->pos().x(),player2->pos().y() - 10,2))  player2Move(0);
            else{
                if(CheckBlock(player2->pos().x() + 10,player2->pos().y(),2))  player2Move(3);
                else{
                   if(CheckBlock(player2->pos().x(),player2->pos().y() + 10,2))  player2Move(1);
                   else{
                       if(CheckBlock(player2->pos().x() - 10,player2->pos().y(),2))  player2Move(2);
                   }
                }
            }
        }
        else if(interval_x<0&&interval_y<0&&interval_x<interval_y){
            if(CheckBlock(player2->pos().x() + 10,player2->pos().y(),2))  player2Move(3);
            else{
                if(CheckBlock(player2->pos().x(),player2->pos().y() + 10,2))  player2Move(1);
                else{
                   if(CheckBlock(player2->pos().x(),player2->pos().y() - 10,2))  player2Move(0);
                   else{
                       if(CheckBlock(player2->pos().x() - 10,player2->pos().y(),2))  player2Move(2);
                   }
                }
            }
        }
        else if(interval_x<0&&interval_y<0&&interval_x>interval_y){
            if(CheckBlock(player2->pos().x(),player2->pos().y() + 10,2))  player2Move(1);
            else{
                if(CheckBlock(player2->pos().x() + 10,player2->pos().y(),2))  player2Move(3);
                else{
                   if(CheckBlock(player2->pos().x(),player2->pos().y() - 10,2))  player2Move(0);
                   else{
                       if(CheckBlock(player2->pos().x() - 10,player2->pos().y(),2))  player2Move(2);
                   }
                }
            }
        }
        else if(interval_x>0&&interval_y<0&&interval_x>-interval_y){
            if(CheckBlock(player2->pos().x() - 10,player2->pos().y(),2))  player2Move(2);
            else{
                if(CheckBlock(player2->pos().x(),player2->pos().y() + 10,2))  player2Move(1);
                else{
                   if(CheckBlock(player2->pos().x(),player2->pos().y() - 10,2))  player2Move(0);
                   else{
                       if(CheckBlock(player2->pos().x() + 10,player2->pos().y(),2))  player2Move(3);
                   }
                }
            }
        }
        else if(interval_x>0&&interval_y<0&&interval_x<-interval_y){
            if(CheckBlock(player2->pos().x(),player2->pos().y() + 10,2))  player2Move(1);
            else{
                if(CheckBlock(player2->pos().x() - 10,player2->pos().y(),2))  player2Move(2);
                else{
                    if(CheckBlock(player2->pos().x(),player2->pos().y() - 10,2))  player2Move(0);
                   else{
                        if(CheckBlock(player2->pos().x() + 10,player2->pos().y(),2))  player2Move(3);
                   }
                }
            }
        }
    }
}
void MainWindow::playerMove(int dir){
    switch(dir){
        case 0:
           index_playerX=0;
           index_playerY=2;
           player1->direct=1;
           onestepX=player1->pos().x();
           onestepY=player1->pos().y()-10;
           player1->onestepstop=0;
           playerVX=player_x[index_playerX];
           playerVY=player_y[index_playerY];
            break;
        case 1:
            index_playerX=0;
            index_playerY=1;
            player1->direct=0;
            onestepX=player1->pos().x();
            onestepY=player1->pos().y()+10;
            player1->onestepstop=0;
            playerVX=player_x[index_playerX];
            playerVY=player_y[index_playerY];
            break;
        case 2:
            index_playerX=2;
            index_playerY=0;
            player1->direct=2;
            onestepX=player1->pos().x()-10;
            onestepY=player1->pos().y();
            player1->onestepstop=0;
            playerVX=player_x[index_playerX];
            playerVY=player_y[index_playerY];
            break;
        case 3:
            index_playerX=1;
            index_playerY=0;
            player1->direct=3;
            onestepX=player1->pos().x()+10;
            onestepY=player1->pos().y();
            player1->onestepstop=0;
            playerVX=player_x[index_playerX];
            playerVY=player_y[index_playerY];
            break;
    }
}
void MainWindow::player2Move(int dir){
    switch(dir){
        case 0:
           index_playerX=0;
           index_playerY=2;
           player2->direct=1;
           P2onestepX=player2->pos().x();
           P2onestepY=player2->pos().y()-10;
           player2->onestepstop=0;
           player2VX=player_x[index_playerX];
           player2VY=player_y[index_playerY];
            break;
        case 1:
            index_playerX=0;
            index_playerY=1;
            player2->direct=0;
            P2onestepX=player2->pos().x();
            P2onestepY=player2->pos().y()+10;
            player2->onestepstop=0;
            player2VX=player_x[index_playerX];
            player2VY=player_y[index_playerY];
            break;
        case 2:
            index_playerX=2;
            index_playerY=0;
            player2->direct=2;
            P2onestepX=player2->pos().x()-10;
            P2onestepY=player2->pos().y();
            player2->onestepstop=0;
            player2VX=player_x[index_playerX];
            player2VY=player_y[index_playerY];
            break;
        case 3:
            index_playerX=1;
            index_playerY=0;
            player2->direct=3;
            P2onestepX=player2->pos().x()+10;
            P2onestepY=player2->pos().y();
            player2->onestepstop=0;
            player2VX=player_x[index_playerX];
            player2VY=player_y[index_playerY];
            break;
    }
}
void MainWindow::SetBomb(int x, int y){
    //player1
    for(int i=0;i<Bombnum;i++){
        if(bombs[i]->mode == 0){
            int tmp_x = (x-x%50 > 25)? x-x%50-50:x-x%50;
            int tmp_y = (y-y%50 > 25)? y-y%50-50:y-y%50;
            if(AreaCheck(tmp_x, tmp_y) == 2){

                bombfgm->play();
                bombs[i]->cur_x = tmp_x;
                bombs[i]->cur_y = tmp_y;
                bombs[i]->mode = 1;
                bombs[i]->bombTimer->start(bombtimedata);
                bombs[i]->show();
                return;
            }
        }
    }
}
void MainWindow::SetBomb2(int x, int y){
    //player2
    for(int i=0;i<Bomb2num;i++){
        if(bombs2[i]->mode == 0){
            int tmp_x = (x-x%50 > 25)? x-x%50-50:x-x%50;
            int tmp_y = (y-y%50 > 25)? y-y%50-50:y-y%50;
            if(AreaCheck(tmp_x, tmp_y) == 2){
                player2->LeaveBomb[i] = 0;
                bombfgm->play();
                bombs2[i]->cur_x = tmp_x;
                bombs2[i]->cur_y = tmp_y;
                bombs2[i]->mode = 1;
                bombs2[i]->bombTimer->start(bombtimedata);
                bombs2[i]->show();
                return;
            }
        }
    }
}
void MainWindow::SetItem(int x, int y, int type){

    for(int i=0;i<itemCount;i++){
        if(items[i]->mode == 0){

            items[i]->cur_x = x + 50;
            items[i]->cur_y = y + 50;
            /*0 跑速  3~4 水球  7~8 範圍 */
            if(type == 0){
                items[i]->mode = 1;
                items[i]->itemPic = 2;
                items[i]->show();
            }
            else if(type >=3 && type < 5){
                items[i]->mode = 1;
                items[i]->itemPic = 0;
                items[i]->show();
            }
            else if(type >= 7  && type < 9){
                items[i]->mode = 1;
                items[i]->itemPic = 1;
                items[i]->show();
            }
            return;
        }
    }
}
int MainWindow::CheckBlock(int x,int y,int target)
{
    //x:玩家x y:玩家y
    int FunMode = 0;
    //block
    for(int i=0; i<blockCount; i++)
    {
        FunMode = AreaOverlap(x,y,blocks[i]->cur_x,blocks[i]->cur_y);

        if(!FunMode)return FunMode;
    }
    //breakable
    for(int i=0; i<breakCount; i++)
    {
        if(breaks[i]->mode == 0) continue;
        FunMode = AreaOverlap(x,y,breaks[i]->cur_x,breaks[i]->cur_y);
        if(!FunMode)return FunMode;
    }

    if(target == 1){
        //bomb
        for(int i=0;i<bombCount;i++){
            if(bombs2[i]->mode == 1){
                FunMode = AreaOverlap(x,y,bombs2[i]->cur_x + 50,bombs2[i]->cur_y + 50);
                if(!FunMode)    return 0;
            }
        }
        //items
        for(int i=0;i<itemCount;i++){
            if(items[i]->mode == 0) continue;

            FunMode = AreaOverlap(x,y,items[i]->cur_x,items[i]->cur_y);
            if(!FunMode){
                if(items[i]->mode == 1){
                    items[i]->mode = 0;
                    items[i]->close();
                    if(items[i]->itemPic == 0){
                        if(Bombnum < 5) Bombnum++;
                    }
                    else if(items[i]->itemPic == 1){
                        for(int j=0;j<bombCount;j++){
                            if(bombs[j]->bombrange < 7)  bombs[j]->bombrange++;
                        }
                    }else if(items[i]->itemPic == 2){
                        if(player1timedata > 0.00001){
                            player1timedata /= 10;
                            playerTimer->start(player1timedata);
                        }
                    }
                    return 1;
                }
            }
        }
    }
    else if(target == 2 && player2->mode == 1){

        for(int i=0;i<bombCount;i++){
            if(bombs[i]->mode == 1){
                FunMode = AreaOverlap(x,y,bombs[i]->cur_x + 50,bombs[i]->cur_y + 50);
                if(!FunMode)    return 0;
            }
        }

        for(int i=0;i<itemCount;i++){
            if(items[i]->mode == 0) continue;
            FunMode = AreaOverlap(x,y,items[i]->cur_x,items[i]->cur_y);
            if(!FunMode){
                if(items[i]->mode == 1){
                    items[i]->mode = 0;
                    items[i]->close();
                    if(items[i]->itemPic == 0){
                        if(Bombnum < 5) Bomb2num++;
                    }
                    else if(items[i]->itemPic == 1){
                        for(int j=0;j<bombCount;j++){
                            if(bombs2[j]->bombrange < 7)  bombs2[j]->bombrange++;
                        }
                    }else if(items[i]->itemPic == 2){
                        if(player2timedata > 0.00001){
                            player2timedata /= 10;
                            playerTimer->start(player2timedata);
                        }
                    }
                    return 1;
                }
            }
        }
    }else if(target == 2 && player2->mode == 0){

        for(int i=0;i<bombCount;i++){
            if(bombs[i]->mode == 1){
                FunMode = AreaOverlap(x,y,bombs[i]->cur_x+50,bombs[i]->cur_y+50);
                if(!FunMode)    return FunMode;
            }
        }
    }

    return 1;
}
int MainWindow::AreaOverlap(int x, int y,int pos_x,int pos_y){

    int blockx,blocky;
    int Wplayer=42,Hplayer=58,Wblock=46,Hblock=15;
    int overlapW=0,overlapH=0;

    blockx=pos_x;
    blocky=pos_y;
    if( x <blockx )
    {
        if((x+Wplayer) > blockx && (x+Wplayer) < (blockx+Wblock))
            overlapW= x+Wplayer-blockx;
        else if( (x+Wplayer) >= blockx+Wblock )
            overlapW= Wblock;
        else
            overlapW = 0;
    }
    else if( x > blockx)
    {
        if((blockx+Wblock) > x && (blockx+Wblock) < (x+Wplayer))
            overlapW=blockx+Wblock-x;
        else if( (blockx+Wblock) >= (x+Wplayer) )
            overlapW=Wplayer;
        else
            overlapW= 0;
    }
    else
    {
        if(Wplayer<=Wblock)
            overlapW=Wplayer;
        else
            overlapW=Wblock;
    }

    if( y <blocky )
    {
        if((y+Hplayer) > blocky && (y+Hplayer) < (blocky+Hblock))
            overlapH= y+Hplayer-blocky;
        else if( (y+Hplayer) >= blocky+Hblock )
            overlapH= Hblock;
        else
            overlapH= 0;
    }
    else if( y > blocky)
    {
        if((blocky+Hblock) > y && (blocky+Hblock) < (y+Hplayer))
            overlapH=blocky+Hblock-y;
        else if( (blocky+Hblock) >= (y+Hplayer) )
            overlapH=Wplayer;
        else
            overlapH= 0;
    }
    else
    {
        if(Hplayer<=Hblock)
            overlapH=Hplayer;
        else
            overlapH=Hblock;
    }

    if(overlapW*overlapH>0)        return 0;
    else    return 1;
}
int MainWindow::AreaCheck(int x, int y){

    // 0牆  1breakable 2空白 3水球 4玩家
    for(int i=0;i<blockCount;i++){
        if(x==blocks[i]->cur_x-50 && y==blocks[i]->cur_y-50){
            return 0;
        }
    }

    for(int i=0;i<breakCount;i++){
        if(x==breaks[i]->cur_x-50 && y==breaks[i]->cur_y-50 && breaks[i]->mode == 1){
            breaks[i]->mode = 0;
            SetItem(x,y,rand()%11);
            return 1;
        }
    }
    for(int i=0;i<bombCount;i++){
        if(x==bombs[i]->cur_x && y==bombs[i]->cur_y && bombs[i]->mode == 1)     return 3;
        if(x==bombs2[i]->cur_x && y==bombs2[i]->cur_y && bombs2[i]->mode == 1)  return 3;
    }

    return 2;
}
int MainWindow::bombHit(int x, int y){

    //x,y 爆炸圖的點
    // 1 玩家 2 P2
    if(player1->pos().x()+25 >= x+50 && player1->pos().x()+25 <= x+100 && player1->pos().y()+32 >= y+50 && player1->pos().y()+32 <= y+100 ) return 1;
    if(player2->pos().x()+25 >= x+50 && player2->pos().x()+25 <= x+100 && player2->pos().y()+32 >= y+50 && player2->pos().y()+32 <= y+100 ) return 2;
    return 0;
}
void MainWindow::Explosion(Bomb *bomb){

    static int time = 0;

    if(bomb->mode == 2 )    return;
    else time = 0;
    if(time==0)       explosionfgm->play();
    bomb->mode = 2;

    time++;

    int Emode = 0;  //炸到何物 0:牆 1:breakable 2:空白
    //上下左右

    if(player1->pos().x()+25 >=  bomb->cur_x +50 && player1->pos().x()+25 <= bomb->cur_x+100 && player1->pos().y()+32 >= bomb->cur_y+50 && player1->pos().y()+32 <= bomb->cur_y+100)    GameEnd(0);
    if(player2->pos().x()+25 >=  bomb->cur_x +50 && player2->pos().x()+25 <= bomb->cur_x+100 && player2->pos().y()+32 >= bomb->cur_y+50 && player2->pos().y()+32 <= bomb->cur_y+100)    GameEnd(1);
    for(int i=1;i <= bomb->bombrange;i++){
        if(bomb->cur_y - i*50 == -50){
            bomb->uprange = i-1;
            break;
        }

        Emode = AreaCheck(bomb->cur_x,bomb->cur_y - i*50);
        if(Emode == 0){
            bomb->uprange = i-1;
            break;
       }else if(Emode == 1){
            bomb->uprange = i;
            break;
       }else bomb->uprange = i;


        int type = bombHit(bomb->cur_x , bomb->cur_y - i*50);
        //炸到玩家
        if(type == 1)   GameEnd(0);
        //炸到AI
        else if(type == 2)   GameEnd(1);

    }
    for(int i=1;i<=bomb->bombrange;i++){
        if(bomb->cur_y + i*50 == 750){
            bomb->downrange = i-1;
            break;
        }

        Emode = AreaCheck(bomb->cur_x,bomb->cur_y + i*50);
        if(Emode == 0){
            bomb->downrange = i-1;
            break;
       }else if(Emode == 1){
            bomb->downrange = i;
            break;
       }else bomb->downrange = i;
       int type = bombHit(bomb->cur_x , bomb->cur_y + i*50);
       if(type == 1)  GameEnd(0);
       else if(type == 2)  GameEnd(1);
    }
    for(int i=1;i<=bomb->bombrange;i++){
        if(bomb->cur_x - i*50 == 0){
            bomb->leftrange = i-1;
            break;
        }

        Emode = AreaCheck(bomb->cur_x - i*50,bomb->cur_y);
        if(Emode == 0){
            bomb->leftrange =i-1;
            break;
        }else if(Emode == 1){
            bomb->leftrange = i;
            break;
       }else bomb->leftrange = i;
        int type = bombHit(bomb->cur_x - i*50, bomb->cur_y);
        if(type == 1)  GameEnd(0);
        else if(type == 2)  GameEnd(1);
    }
    for(int i=1;i<=bomb->bombrange;i++){
        if(bomb->cur_x + i*50 == 750){
            bomb->rightrange = i-1;
            break;
        }

        Emode = AreaCheck(bomb->cur_x + i*50,bomb->cur_y);
        if(Emode == 0){
            bomb->rightrange = i-1;
            break;
        }else if(Emode == 1){
            bomb->rightrange = i;
            break;
       }else bomb->rightrange = i;
        int type = bombHit(bomb->cur_x + i*50, bomb->cur_y);
        if(type == 1)  GameEnd(0);
        else if(type == 2)  GameEnd(1);
    }

    DetectBomb(bomb);
}
/*chain explosion*/
void MainWindow::DetectBomb(Bomb *bomb){

    //上
    for(int i=0;i<=bomb->uprange;i++){
        for(int j=0;j<bombCount;j++){

            if(bombs[j]->mode == 1 && bombs[j]!=bomb){
                if(bomb->cur_x == bombs[j]->cur_x && bomb->cur_y == bombs[j]->cur_y - i*50 + 50)  Explosion(bombs[j]);
            }
        }

        for(int j=0;j<bombCount;j++){

            if(bombs2[j]->mode == 1 && bombs2[j]!=bomb){
                if(bomb->cur_x == bombs2[j]->cur_x && bomb->cur_y == bombs2[j]->cur_y - i*50 + 50)  Explosion(bombs2[j]);
            }
        }
    }
    //下
    for(int i=0;i<=bomb->downrange;i++){
        for(int j=0;j<bombCount;j++){
           if(bombs[j]->mode == 1 && bombs[j]!=bomb){
                if(bomb->cur_x == bombs[j]->cur_x && bomb->cur_y + 50 == bombs[j]->cur_y + i*50)  Explosion(bombs[j]);
            }
        }

        for(int j=0;j<bombCount;j++){

            if(bombs2[j]->mode == 1 && bombs2[j]!=bomb){
                if(bomb->cur_x == bombs2[j]->cur_x && bomb->cur_y +50 == bombs2[j]->cur_y + i*50)  Explosion(bombs2[j]);
            }
        }
    }
    //左
    for(int i=0;i<=bomb->leftrange;i++){
        for(int j=0;j<bombCount;j++){

            if(bombs[j]->mode == 1 && bombs[j]!=bomb){
                if(bomb->cur_x == bombs[j]->cur_x - i*50 && bomb->cur_y == bombs[j]->cur_y)  Explosion(bombs[j]);
            }
        }
        for(int j=0;j<bombCount;j++){

            if(bombs2[j]->mode == 1 && bombs2[j]!=bomb){
                if(bomb->cur_x == bombs2[j]->cur_x - i*50 && bomb->cur_y == bombs2[j]->cur_y)  Explosion(bombs2[j]);
            }
        }
    }
    //右
    for(int i=0;i<=bomb->rightrange;i++){
        for(int j=0;j<bombCount;j++){

            if(bombs[j]->mode == 1 && bombs[j]!=bomb){
                if(bomb->cur_x == bombs[j]->cur_x + 50 + i*50 && bomb->cur_y == bombs[j]->cur_y)  Explosion(bombs[j]);
            }
        }
        for(int j=0;j<bombCount;j++){

            if(bombs2[j]->mode == 1 && bombs2[j]!=bomb){
                if(bomb->cur_x == bombs2[j]->cur_x + 50 + i*50 && bomb->cur_y == bombs2[j]->cur_y)  Explosion(bombs2[j]);
            }
        }
    }

}
void MainWindow::GameReady(){
    gamemode = ready;
    help->close();
    credit->close();
    SMs->show();
    bgPic = 0;
    Bombnum = Bomb2num = 1;
    createPlayer();
    createPlayer2();
    createBomb();
    createDC();
    createHelp();
    createItem();
    firstbgm->play();

    endloseOrder=0;
    enddieOrder=0;
    endwinOrder=0;
    endliveOrder=0;
}
void MainWindow::GameHelp(){
    gamemode = helpmode;
    bgPic = 2;
    help->show();
    HelpTimer->start(helptimedata);
    SMs->close();
}
void MainWindow::GameCredit(){
    gamemode = creditmode;
    bgPic = 3;
    SMs->close();
    credit->show();
}
void MainWindow::GameStart(int mode){
    //gamemode = start;
    if(mode == 0){
        bgPic=1;
        player2->mode=0;
        player2timedata = 100;
        gamemode = AI;

    }else if(mode == 1){
        bgPic=4;
        player2->mode=1;
        player2timedata = 1;
        gamemode = VS;
    }


    firstbgm->stop();
    SMs->close();
    createBreak();
    createBlock();

    playerTimer->start(player1timedata);
    player2Timer->start(player2timedata);
    player1->show();
    player2->show();

    DC->Start = 1;
    DCTimer->start(DCtimedata);
    DC->show();


    bgm1->play();

    for(int i=0;i<blockCount;i++){
        blocks[i]->show();
        blocks[i]->mode = 1;
    }


    for(int i=0;i<breakCount;i++){
        breaks[i]->show();
        breaks[i]->mode = 1;
    }

}
void MainWindow::GameEnd(int mode){

    gamemode = end;
    //停止玩家1
    playerTimer->stop();
    //player->stop();
    //停止玩家2
    player2Timer->stop();
    //關閉倒數計時器
    DCTimer->stop();
    DC->close();
    bgm1->stop();
    player1->close();
    player2->close();
    for(int i=0;i<bombCount;i++){
        bombs[i]->bombTimer->stop();
        bombs[i]->close();
        bombs2[i]->bombTimer->stop();
        bombs2[i]->close();
    }
    for(int i=0;i<itemCount;i++){
        items[i]->mode = 0;
        items[i]->close();
    }
    for(int i=0;i<breakCount;i++){
        breaks[i]->mode = 0;
        breaks[i]->close();
    }
    for(int i=0;i<blockCount;i++){
        blocks[i]->mode = 0;
        blocks[i]->close();
    }
    //決定遊戲畫面
    if(mode == 0){
        losefgm->play();
        win = false;
    }
    else{
        winfgm->play();
        win = true;
    }
}

void MainWindow::Bomb1Action(){
    bombs[0]->close();
    if(bombs[0]->bombinterval < 22 && bombs[0]->mode==1){
        bombs[0]->bombinterval++;
        bombs[0]->bombPic = (bombs[0]->bombPic + 1)%3;
    }else if(bombs[0]->bombinterval >= 22 && bombs[0]->mode == 1){
        Explosion(bombs[0]);
    }else if(bombs[0]->mode == 3){
        bombs[0]->bombinterval = 0;
        bombs[0]->mode = 0;
        bombs[0]->close();
        bombs[0]->bombTimer->stop();
    }else if(bombs[0]->mode == 0){
        bombs[0]->close();
        bombs[0]->bombTimer->stop();
    }

    if(bombs[0]->mode!=0)  bombs[0]->show();
}
void MainWindow::Bomb2Action(){
    bombs[1]->close();
    if(bombs[1]->bombinterval < 22 && bombs[1]->mode==1){
        bombs[1]->bombinterval++;
        bombs[1]->bombPic = (bombs[1]->bombPic + 1)%3;
    }else if(bombs[1]->bombinterval >= 22 && bombs[1]->mode == 1){
        Explosion(bombs[1]);
    }else if(bombs[1]->mode == 3){
        bombs[1]->bombinterval = 0;
        bombs[1]->mode = 0;
        bombs[1]->close();
        bombs[1]->bombTimer->stop();
    }else if(bombs[1]->mode == 0){
        bombs[1]->close();
        bombs[1]->bombTimer->stop();
    }

    if(bombs[1]->mode!=0)  bombs[1]->show();
}
void MainWindow::Bomb3Action(){
    bombs[2]->close();
    if(bombs[2]->bombinterval < 22 && bombs[2]->mode==1){
        bombs[2]->bombinterval++;
        bombs[2]->bombPic = (bombs[2]->bombPic + 1)%3;
    }else if(bombs[2]->bombinterval >= 22 && bombs[2]->mode == 1){
        Explosion(bombs[2]);
    }else if(bombs[2]->mode == 3){
        bombs[2]->bombinterval = 0;
        bombs[2]->mode = 0;
        bombs[2]->close();
        bombs[2]->bombTimer->stop();
    }else if(bombs[2]->mode == 0){
        bombs[2]->close();
        bombs[2]->bombTimer->stop();
    }

    if(bombs[2]->mode!=0)  bombs[2]->show();
}
void MainWindow::Bomb4Action(){
    bombs[3]->close();
    if(bombs[3]->bombinterval < 22 && bombs[3]->mode==1){
        bombs[3]->bombinterval++;
        bombs[3]->bombPic = (bombs[3]->bombPic + 1)%3;
    }else if(bombs[3]->bombinterval >= 22 && bombs[3]->mode == 1){
        Explosion(bombs[3]);
    }else if(bombs[3]->mode == 3){
        bombs[3]->bombinterval = 0;
        bombs[3]->mode = 0;
        bombs[3]->close();
        bombs[3]->bombTimer->stop();
    }else if(bombs[3]->mode == 0){
        bombs[3]->close();
        bombs[3]->bombTimer->stop();
    }

    if(bombs[3]->mode!=0)  bombs[3]->show();
}
void MainWindow::Bomb5Action(){
    bombs[4]->close();
    if(bombs[4]->bombinterval < 22 && bombs[4]->mode==1){
        bombs[4]->bombinterval++;
        bombs[4]->bombPic = (bombs[4]->bombPic + 1)%3;
    }else if(bombs[4]->bombinterval >= 22 && bombs[4]->mode == 1){
        Explosion(bombs[4]);
    }else if(bombs[4]->mode == 3){
        bombs[4]->bombinterval = 0;
        bombs[4]->mode = 0;
        bombs[4]->close();
        bombs[4]->bombTimer->stop();
    }else if(bombs[4]->mode == 0){
        bombs[4]->close();
        bombs[4]->bombTimer->stop();
    }

    if(bombs[4]->mode!=0)  bombs[4]->show();
}
void MainWindow::Bomb6Action(){
    bombs2[0]->close();
    if(bombs2[0]->bombinterval < 22 && bombs2[0]->mode==1){
        bombs2[0]->bombinterval++;
        bombs2[0]->bombPic = (bombs2[0]->bombPic + 1)%3;
    }else if(bombs2[0]->bombinterval >= 22 && bombs2[0]->mode == 1){
        Explosion(bombs2[0]);
    }else if(bombs2[0]->mode == 3){
        bombs2[0]->bombinterval = 0;
        bombs2[0]->mode = 0;
        bombs2[0]->close();
        bombs2[0]->bombTimer->stop();
    }else if(bombs2[0]->mode == 0){
        bombs2[0]->close();
        bombs2[0]->bombTimer->stop();
    }

    if(bombs2[0]->mode!=0)  bombs2[0]->show();
}
void MainWindow::Bomb7Action(){
    bombs2[1]->close();
    if(bombs2[1]->bombinterval < 22 && bombs2[1]->mode==1){
        bombs2[1]->bombinterval++;
        bombs2[1]->bombPic = (bombs2[1]->bombPic + 1)%3;
    }else if(bombs2[1]->bombinterval >= 22 && bombs2[1]->mode == 1){
        Explosion(bombs2[1]);
    }else if(bombs2[1]->mode == 3){
        bombs2[1]->bombinterval = 0;
        bombs2[1]->mode = 0;
        bombs2[1]->close();
        bombs2[1]->bombTimer->stop();
    }else if(bombs2[1]->mode == 0){
        bombs2[1]->close();
        bombs2[1]->bombTimer->stop();
    }

    if(bombs2[1]->mode!=0)  bombs2[1]->show();
}
void MainWindow::Bomb8Action(){
    bombs2[2]->close();
    if(bombs2[2]->bombinterval < 22 && bombs2[2]->mode==1){
        bombs2[2]->bombinterval++;
        bombs2[2]->bombPic = (bombs2[2]->bombPic + 1)%3;
    }else if(bombs2[2]->bombinterval >= 22 && bombs2[2]->mode == 1){
        Explosion(bombs2[2]);
    }else if(bombs2[2]->mode == 3){
        bombs2[2]->bombinterval = 0;
        bombs2[2]->mode = 0;
        bombs2[2]->close();
        bombs2[2]->bombTimer->stop();
    }else if(bombs2[2]->mode == 0){
        bombs2[2]->close();
        bombs2[2]->bombTimer->stop();
    }

    if(bombs2[2]->mode!=0)  bombs2[2]->show();
}
void MainWindow::Bomb9Action(){
    bombs2[3]->close();
    if(bombs2[3]->bombinterval < 22 && bombs2[3]->mode==1){
        bombs2[3]->bombinterval++;
        bombs2[3]->bombPic = (bombs2[3]->bombPic + 1)%3;
    }else if(bombs2[3]->bombinterval >= 22 && bombs2[3]->mode == 1){
        Explosion(bombs2[3]);
    }else if(bombs2[3]->mode == 3){
        bombs2[3]->bombinterval = 0;
        bombs2[3]->mode = 0;
        bombs2[3]->close();
        bombs2[3]->bombTimer->stop();
    }else if(bombs2[3]->mode == 0){
        bombs2[3]->close();
        bombs2[3]->bombTimer->stop();
    }

    if(bombs2[3]->mode!=0)  bombs2[3]->show();
}
void MainWindow::Bomb10Action(){
    bombs2[4]->close();
    if(bombs2[4]->bombinterval < 22 && bombs2[4]->mode==1){
        bombs2[4]->bombinterval++;
        bombs2[4]->bombPic = (bombs2[4]->bombPic + 1)%3;
    }else if(bombs2[4]->bombinterval >= 22 && bombs2[4]->mode == 1){
        Explosion(bombs2[4]);
    }else if(bombs2[4]->mode == 3){
        bombs2[4]->bombinterval = 0;
        bombs2[4]->mode = 0;
        bombs2[4]->close();
        bombs2[4]->bombTimer->stop();
    }else if(bombs2[4]->mode == 0){
        bombs2[4]->close();
        bombs2[4]->bombTimer->stop();
    }

    if(bombs2[4]->mode!=0)  bombs2[4]->show();
}
