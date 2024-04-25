#include "food.h"
#include "config.h"
food::food()
{
    //苹果资源加载
    m_food1.load(FOOD1_PATH);
    //苹果位置
    m_X=GAME_WIDTH;
    m_Y=242;
    //苹果状态
    m_Free=true;
    //苹果速度
    m_Speed=ENEMY1_SPEED;
    //苹果矩阵框（碰撞检测）
    m_Rect.setWidth(40);
    m_Rect.setHeight(42);
    m_Rect.moveTo(m_X,m_Y);
}

void food::CreateRect()
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

