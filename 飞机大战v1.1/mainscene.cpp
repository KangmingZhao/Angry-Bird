#include "mainscene.h"
#include "config.h"
#include<QIcon>
#include<QPainter>
#include<QTimer>
#include"bullet.h"
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    //初始化
    initScene();
}

MainScene::~MainScene()
{

}
void MainScene::initScene(){
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    //设置图标资源
    setWindowIcon(QIcon(GAME_ICON));
    m_Timer.setInterval(GAME_RATE);
    playgame();

}
void MainScene::playgame(){
    m_Timer.start();

    connect(&m_Timer, &QTimer::timeout, [=](){


        //更新元素
        updatePosition();

        //更新绘制
        update();
    });
}
void MainScene::updatePosition(){

    m_map.mapPosition();
    //cwshi
  m_p.shoot();
  for(int i=0;i<BULLET_NUM;i++)
  {
      //发射
      if(!m_p.m_bullets[i].m_Free)
      {
        m_p.m_bullets[i].updatePosition();
      }
  }

}
void MainScene::paintEvent(QPaintEvent *event)

{

    QPainter painter(this);
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
            painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);
            painter.drawPixmap(m_p.m_x,m_p.m_y,m_p.m_Plane);
            //ceshi

            for(int i = 0 ;i < BULLET_NUM;i++)
           {
            //如果子弹状态为非空闲，计算发射位置
                if(!m_p.m_bullets[i].m_Free)
            {

            painter.drawPixmap(m_p.m_bullets[i].m_x,m_p.m_bullets[i].m_y,m_p.m_bullets[i].m_Bullet);
            }
          }

}
void MainScene::mouseMoveEvent(QMouseEvent *event)
{
int x = event->x() - m_p.m_Rect.width()*0.5;
//鼠标位置
int y = event->y() - m_p.m_Rect.height()*0.5;

//边界检测
if(x <= 0 )
{
x = 0;
}
if(x >= GAME_WIDTH - m_p.m_Rect.width())
{
x = GAME_WIDTH - m_p.m_Rect.width();
}
if(y <= 0)
{
y = 0;
}
if(y >= GAME_HEIGHT - m_p.m_Rect.height())
{
y = GAME_HEIGHT - m_p.m_Rect.height();
}
m_p.setPosition(x,y);
}
