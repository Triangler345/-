#ifndef DINOSAUR_H
#define DINOSAUR_H
#include <QPixmap>
#include <QRect>
#include "config.h"
#include <QVector>
#include <QTimer>
#include <QWidget>
#include "Bullet.h"
class dinosaur
{
public:
    dinosaur();
    //发射子弹
    void shoot();
    void setPosition(int x,int y);
    void updateInfo();

public:

    //放恐龙资源数组
    QVector<QPixmap> m_pixArr;
    //恐龙资源 对象
    QPixmap m_dinosaur1;
    //QPixmap m_dinosaur2;
    QPixmap gameover;

    //恐龙坐标
    int m_X;
    int m_Y;

    //恐龙的矩形边框
    QRect m_Rect;
    //切图的时间间隔
    int m_Recorder;
    //加载的图片下标
    int m_index;
    //弹匣
    Bullet m_bullets[BULLET_NUM];
    //发射间隔记录
    int m_recorder;

};

#endif // DINOSAUR_H
