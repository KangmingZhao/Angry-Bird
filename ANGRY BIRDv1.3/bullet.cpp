#include "bullet.h"
#include"config.h"
bullet::bullet()
{
  //加载子弹
    m_Bullet.load(BULL_PATH);
    //子弹坐标
    m_x=GAME_WIDTH*0.5-m_Bullet.width()*2;
    m_y=GAME_HEIGHT;
    m_Free=true;
    m_Speed=BULL_SPEED;
    //矩形框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_x,m_y);
}
void bullet::updatePosition()
{
    if(m_Free==true){
        return;
    }
    m_y-=m_Speed;
    m_Rect.moveTo(m_x,m_y);
    if(m_y<=-m_Rect.height())
    {
        m_Free=true;
    }
}
