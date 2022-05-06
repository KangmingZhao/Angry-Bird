#include "plane.h"
#include"config.h"

plane::plane()
{
    //初始化加载飞机图片资源
    m_Plane.load(PLANE_PATH);

    //初始化坐标
    m_x = GAME_WIDTH * 0.5 - m_Plane.width()*0.5; m_y = GAME_HEIGHT - m_Plane.height();

    //初始化矩形框
    m_Rect.setWidth(m_Plane.width()); m_Rect.setHeight(m_Plane.height()); m_Rect.moveTo(m_x,m_y);

//初始化发射间隔
    m_recorder=0;
    m_bulletnum=60;
}
void plane::setPosition(int x, int y)

{
    m_x = x; m_y = y;
    m_Rect.moveTo(m_x,m_y);
    }

    void plane::shoot()
    {  //时间变化
        m_recorder++;
        //判断如果记录数字 未达到发射间隔，直接return
        if(m_recorder < BULLET_INTERVAL)
        {
        return;
        }
        //到达发射时间处理
        //重置发射时间间隔记录
        m_recorder = 0;
        //发射子弹
        for(int i = 0 ; i < BULLET_NUM;i++)
        {
        //如果是空闲的子弹进行发射
            if(m_bullets[i].m_Free)
        {
        //将改子弹空闲状态改为假
                m_bullets[i].m_Free = false;
                m_bulletnum--;
        //设置发射的子弹坐标
        m_bullets[i].m_x = m_x+ m_Rect.width()*0.5 - 10;
        m_bullets[i].m_y = m_y - 25 ;
        break;
        }
        }

    }

