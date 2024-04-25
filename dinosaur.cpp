#include "dinosaur.h"
#include "config.h"
#include <QTimerEvent>
#include <QPixmap>
#include <QTimer>
#include <QString>
dinosaur::dinosaur()
{
    //初始化加载恐龙图片资源
    m_dinosaur1.load(DINOSAUR_PATH);
    //m_dinosaur2.load(DINOSAUR_PATH);
    gameover.load(DINOSAUROVER_PATH);
    //将所有pixmap放入到数组中
    for(int i=1;i<=DINOSAUR_MAX;i++)
    {
        //str相当于":res/rsesourse/dinosaur%1.png"
        QString str=QString(DINOSAUR_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));//插入准备好的路径
    }
    //初始化恐龙坐标
    m_X=m_dinosaur1.width();
    m_Y=m_dinosaur1.height();
    //初始化矩形边框
    m_Rect.setWidth(100);
    m_Rect.setHeight(100);
    m_Rect.moveTo(m_X,m_Y);
    //播放当前图片下标
    m_index=0;
    //播放爆炸间隔记录
    m_Recorder=0;

}
void dinosaur::shoot()
{
    //累加时间间隔记录变量
    m_recorder++;
    //如果记录的数字未达到发射子弹的时间间隔，直接return，不发射子弹
    if(m_recorder<BULLET_INTERVAL)
    {
        return;
    }
    //达到发射时间
    m_recorder=0;
    //发射子弹
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果是空闲的子弹就发射
        if(m_bullets[i].m_Free)
        {
            //将当前子弹空闲状态改为假
            m_bullets[i].m_Free=false;
            //设置子弹坐标
            m_bullets[i].m_X=m_X+m_Rect.width()*0.5-10;
            m_bullets[i].m_Y=m_Y-25;
            break;
        }
    }
}
void dinosaur::setPosition(int x, int y)
{
    m_X=x;
    m_Y=y;
    m_Rect.moveTo(m_X,m_Y);
}
void dinosaur::updateInfo()
{
    m_Recorder++;//如果记录的时间实际未到达间隔，不需要切图，直接return
    if(m_Recorder<DINOSAUR_INTERVAL)
    {
        return;
    }
    //重置记录
    m_Recorder=0;
    //切换播放的图片下标
    m_index++;
    //数组中下标从0开始计算，最后一个图片的下标为1
    //计算的下标大于1，重置为0
    if(m_index>DINOSAUR_MAX-1)
    {
        m_index=0;
    }
}
