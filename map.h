#ifndef MAP_H
#define MAP_H
#include <QPixmap>
class Map
{

public:
    Map();//构造函数

    void mapPosition();//地图滚动坐标计算
public:

    QPixmap m_map1;
    QPixmap m_map2;//地图图片对象

    int m_map1_posX;
    int m_map2_posX;//地图Y轴坐标

    int m_scroll_speed;//地图滚动速度

};

#endif // MAP_H
