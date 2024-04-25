#include "pterosaur.h"
#include "config.h"
pterosaur::pterosaur()
{
    //敌人2（翼龙）资源加载
    m_enemy.load(ENEMY2_PATH);
    //敌人2（翼龙）位置
    m_X=GAME_WIDTH;
    m_Y=0;
    //敌人2（翼龙）状态
    m_Free=true;
    //敌人2（翼龙）速度
    m_Speed=ENEMY2_SPEED;
    //敌人2（翼龙）矩阵框（碰撞检测）
    m_Rect.setWidth(100);
    m_Rect.setHeight(100);
    m_Rect.moveTo(m_X,m_Y);
}

void pterosaur::updatePosition()
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
