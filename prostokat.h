#ifndef PROSTOKAT_H
#define PROSTOKAT_H

#include <QWidget>

// class CustomWidget : public QWidget
// {
//     Q_OBJECT
// public:
//     explicit CustomWidget(QWidget *parent = 0);
//     void paintEvent(QPaintEvent *event);
//     void mousePressEvent(QMouseEvent *event);
//     void mouseMoveEvent(QMouseEvent *event);
// private:
//     QPoint m_lastPos;
//     QPoint nowy_punkt;
// };

// #endif // CUSTOMWIDGET_H



class prostokat:public QWidget
{
    Q_OBJECT
public:
    //explicit CustomWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
   //prostokat();
private:
    //QPoint m_lastPos;
    QPoint nowy_punkt;
};

#endif // PROSTOKAT_H
