#include "item.h"

item::item(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1000,1000);
    Pic[0] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/bubble.png";
    Pic[1] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/fluid.png";
    Pic[2] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/roller.png";
    Pic[3] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/town_bluehouse.png";
    Pic[4] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/town_redhouse.png";
    Pic[5] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/town_tree.png";
    Pic[6] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/town_woodbox.png";
    Pic[7] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/town_orangeblock.png";
    Pic[8] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/town_redblock.png";
    Pic[9] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/LOGO.png";
    Pic[10] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/rock.png";
    Pic[11] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/tent1.png";
    Pic[12] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/tent2.png";
    Pic[13] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/cactus.png";
    Pic[14] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/sandcrate.png";
    Pic[15] = "D:/tpchris1/programming/2017_finalproject/final_1/Image/woodcrate.png";
    type = 0;
    mode = 0;
    itemPic = 0;
    cur_x = cur_y = 0;
}
void item::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap item;
    if(mode){
        item.load(Pic[itemPic]);
        painter.drawPixmap(cur_x,cur_y,50,50,item);
    }
}
