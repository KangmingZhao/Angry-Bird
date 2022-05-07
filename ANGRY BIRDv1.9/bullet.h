#ifndef BULLET_H
#define BULLET_H
#include"config.h"
#include<QPixmap>

class bullet
{
public:
    bullet();
    //更新小鸟坐标
    void updatePosition();

    public:
    //小鸟资源对象
    QPixmap m_Bullet;
    //小鸟坐标
    int m_x; int m_y;
    //小鸟移动速度
    int m_Speed;
    //小鸟是否闲置
    bool m_Free;
    //小鸟的矩形边框
    QRect m_Rect;

};

#endif // BULLET_H
