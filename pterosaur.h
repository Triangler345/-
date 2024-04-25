#ifndef PTEROSAUR_H
#define PTEROSAUR_H
#include <QPixmap>
#include <QRect>
class pterosaur
{
public:
    pterosaur();
    //更新坐标
    void updatePosition();
public:
    //翼龙资源对象
    QPixmap m_enemy;
    //位置
    int m_X;
    int m_Y;
    //翼龙的矩形边框（碰撞检测）
    QRect m_Rect;
    //状态
    bool m_Free;
    //速度
    int m_Speed;
};

#endif // PTEROSAUR_H
