#include "bullet.h"
#include "config.h"
Bullet::Bullet()
{
    //加载子弹资源
    m_Bullet.load(BULLET_PATH);
    //子弹坐标
    m_X=120;
    m_Y=240;
    //子弹状态  默认空闲
    m_Free=true;
    //子弹速度
    m_Speed=BULLET_SPEED;
    //子弹边框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
}
void Bullet::updatePosition()
{
    //空闲状态下的子弹，不需要坐标计算
    if(m_Free)
    {
        return;
    }
    //子弹向右移动
    m_Y+=m_Speed;
    m_Rect.moveTo(m_X,m_Y);
    //子弹移动   超出屏幕，重新变为空闲状态
    if(m_Y>GAME_HEIGHT)
    {
        m_Free=true;
    }
}
