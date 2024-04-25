#include "enemy.h"
#include "config.h"
Enemy::Enemy()
{
    //敌人1（仙人掌）资源加载
    m_enemy.load(ENEMY1_PATH);
    //敌人1（仙人掌）位置
    m_X=GAME_WIDTH;
    m_Y=242;
    finish=50;
    //敌人1（仙人掌）状态
    m_Free=true;
    //敌人1（仙人掌）速度
    m_Speed=ENEMY1_SPEED;
    //敌人1（仙人掌）矩阵框（碰撞检测）
    m_Rect.setWidth(50);
    m_Rect.setHeight(80);
    m_Rect.moveTo(m_X,m_Y);
}
void Enemy::updatePosition()
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
