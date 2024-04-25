#ifndef FOOD_H
#define FOOD_H
#include <QRect>
#include <QPixmap>
class food
{
public:
    food();
    void CreateRect();
public:
    //苹果资源对象
    QPixmap m_food1;
    //位置
    int m_X;
    int m_Y;
    //苹果的矩形边框（碰撞检测）
    QRect m_Rect;
    //状态
    bool m_Free;
    //速度
    int m_Speed;
};

#endif // FOOD_H
