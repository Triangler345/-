#include "food2.h"
#include "config.h"
food2::food2()
{
    //金苹果资源加载
    m_food2.load(FOOD2_PATH);
    //金苹果位置
    m_X=GAME_WIDTH;
    m_Y=142;
    //金苹果状态
    m_Free=true;
    //金苹果速度
    m_Speed=FOOD1_SPEED;
    //金苹果矩阵框（碰撞检测）
    m_Rect.setWidth(40);
    m_Rect.setHeight(42);
    m_Rect.moveTo(m_X,m_Y);
}

void food2::CreateRect()
{
    //空闲状态下，不计算坐标
    if(m_Free)
    {
        return;
    }
    m_X-=m_Speed;
    m_Rect.moveTo(m_X,m_Y);
    //如果超出屏幕，重置空闲状态
    if(m_X<=-100)
    {
        m_Free=true;
    }
}
