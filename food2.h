#ifndef FOOD2_H
#define FOOD2_H
#include <QRect>
#include <QPixmap>
class food2
{
public:
    food2();
    void CreateRect();
public:
    //金苹果资源对象
    QPixmap m_food2;
    //位置
    int m_X;
    int m_Y;
    //金苹果的矩形边框（碰撞检测）
    QRect m_Rect;
    //状态
    bool m_Free;
    //速度
    int m_Speed;
};

#endif // FOOD2_H
