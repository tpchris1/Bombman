#ifndef SELECTMODE_H
#define SELECTMODE_H

#include <QWidget>
#include <QWidget>
#include <QTimer>

class SelectMode : public QWidget
{
    Q_OBJECT
public:
    explicit SelectMode(QWidget *parent = 0);
    QTimer *SMTimer;
    double SMtimerdata;
    int choose;
    int mode;   // 0: menu  1:AI 2:VS 3:credit 4:help
protected:
    void paintEvent(QPaintEvent *);

signals:

private:

    QString SMImg[24];
    QString StartModeImg[2];
    QString HelpModeImg[2];
    QString CreditModeImg[2];
    QString VsModeImg[2];
    int SMPic;
    int pos_x,i,pos_y,j;

public slots:
};

#endif // SELECTMODE_H
