#ifndef MAP_H
#define MAP_H
#include<QPixmap>

class map
{
public:
    map();
    void mapPosition();
public:
    //图片对象
    QPixmap m_map1;
    QPixmap m_map2;
    //地图坐标
    int m_map1_posY;
    int m_map2_posY;
    //滚动幅度
    int map_scroll_speed;

};

#endif // MAP_H
