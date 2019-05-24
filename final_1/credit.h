#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>
#include <QTimer>

class Credit : public QWidget
{
    Q_OBJECT
public:
    explicit Credit(QWidget *parent = 0);
    int menumode,choose;
signals:

protected:
    void paintEvent(QPaintEvent *);

private:
    QString MenuModeImg[2];
public slots:
};

#endif // CREDIT_H
