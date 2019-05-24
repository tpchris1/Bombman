#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include <QWidget>
#include <QTimer>

class Help : public QWidget
{
    Q_OBJECT
public:
    explicit Help(QWidget *parent = 0);
    int pos_x1,pos_x2,pos_x3,pos_x4,s_pos_x;
    int startmode,choose;

protected:
    void paintEvent(QPaintEvent *);
signals:

private:
    QString StartModeImg[2];
    QString Instruction[4];

public slots:
};

#endif // HELP_H
