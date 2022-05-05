#ifndef PLANE_H
#define PLANE_H
#include "QPixmap"
#include"QRect"
#include "bullet.h"
class plane
{
public:
    plane();
    void shoot();
    void setPosition(int x,int y);
public:
    QPixmap m_Plane;
   int m_x;
   int m_y;
   QRect m_Rect;
   //弹夹
   bullet m_bullets[BULLET_NUM];
   //发射时间间隔
   int m_recorder;

};

#endif // PLANE_H
