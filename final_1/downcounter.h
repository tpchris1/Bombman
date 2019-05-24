#ifndef DOWNCOUNTER_H
#define DOWNCOUNTER_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>

class DownCounter : public QWidget
{
    Q_OBJECT
public:
    explicit DownCounter(QWidget *parent = 0);
    int Sec;
    int Start;

protected:
    void paintEvent(QPaintEvent *);
private:
    QString src[11];
    QTimer min;
    int block;
};

#endif // DOWNCOUNTER_H
