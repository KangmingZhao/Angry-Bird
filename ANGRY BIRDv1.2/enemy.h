#ifndef ENEMY_H
#define ENEMY_H
#include<QPixmap>

class enemy
{
public:
    enemy();
    void updatePosition();
public:
    QPixmap m_enemy;
    int m_X;
    int m_Y;
    QRect m_Rect;
    bool m_Free;
    int m_Speed;
};

#endif // ENEMY_H
