#include "mainscene.h"
#include "config.h"
#include<QIcon>
#include<QPainter>
#include<QTimer>
#include"bullet.h"
#include<ctime>
#include<QSound>
#include<QMessageBox>
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
   m_recorder = 0;
   score=0;
   m_hp=10;
   //srand((unsigned int)time(NULL));
   gameEnd=false;


}
void MainScene::playgame(){
    m_Timer.start();
     //
    QSound::play(SOUND);
    connect(&m_Timer, &QTimer::timeout, [=](){
         //
        is_stop();
        enemyToScene();
        //更新元素
        updatePosition();

        //更新绘制
        update();
        //碰撞
        collisionDetection();
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
  //猪的坐标计算
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
     //非空闲敌机 更新坐标
     if(m_enemys[i].m_Free == false)
     {
      m_enemys[i].updatePosition();
      }
  }
    //爆炸
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
     if(m_bombs[i].m_Free == false)
      {
         QSound::play(SOUND_BOOM);
       m_bombs[i].updateInfo();

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
            //如果小鸟状态为非空闲，计算发射位置
                if(!m_p.m_bullets[i].m_Free)
            {

            painter.drawPixmap(m_p.m_bullets[i].m_x,m_p.m_bullets[i].m_y,m_p.m_bullets[i].m_Bullet);
            }
          }

            //绘制猪
            for(int i = 0 ; i< ENEMY_NUM;i++)
            {
               if(m_enemys[i].m_Free == false)
               {
               painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
               }
            }
            // 绘制爆炸图片
                        for (int i = 0; i < BOMB_NUM; i++)
                        {
                            if (m_bombs[i].m_Free == false)
                            {

                                painter.drawPixmap(m_bombs[i].m_X, m_bombs[i].m_Y, m_bombs[i].m_pixArr[m_bombs[i].m_index]);
                            }
                        }


       drawRecord(&painter);
if(gameEnd)
{
//    QPainter painter1(this);
//    QFont font;
//    font.setPixelSize(30);
//    font.setFamily("黑体");
//    painter1.save();
//    painter1.setPen(Qt::black);
//    painter1.setFont(font);
//    painter1.drawText(QRect(205,200,200,50),QString("得分：%1").arg(score));
    QPainter painter(this);
    QPixmap pix;
    pix.load("img/GAMEOVER.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    QFont font;
            font.setPixelSize(30);
            font.setFamily("黑体");
            painter.save();
            painter.setPen(Qt::black);
            painter.setFont(font);
            painter.drawText(QRect(185,419,200,50),QString("得分：%1").arg(score));
    return;

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
void MainScene::enemyToScene()
{
   m_recorder++;
   if(m_recorder < ENEMY_INTERVAL)
   {
    return;
    }

    m_recorder = 0;

    for(int i = 0 ; i< ENEMY_NUM;i++)
     {
      if(m_enemys[i].m_Free)
       {
    //敌机空闲状态改为false
       m_enemys[i].m_Free = false;
      //设置坐标
        m_enemys[i].m_X = rand() % (GAME_WIDTH - m_enemys[i].m_Rect.width());
        m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
             break;
       }
     }
}

void MainScene::collisionDetection()
{
    //遍历所有非空闲的敌机
    for (int i = 0; i < ENEMY_NUM; i++)
    {
        if (m_enemys[i].m_Free)
        {
            //空闲飞机 跳转下一次循环
            continue;
        }

        //遍历所有 非空闲的子弹
        for (int j = 0; j < BULLET_NUM; j++)
        {
            if (m_p.m_bullets[j].m_Free)
            {
                //空闲子弹 跳转下一次循环
                continue;
            }

            //如果子弹矩形框和敌机矩形框相交，发生碰撞，同时变为空闲状态即可
            if(m_enemys[i].m_Rect.intersects(m_p.m_bullets[j].m_Rect))
            {   score++;
                m_enemys[i].m_Free = true; m_p.m_bullets[j].m_Free = true;
                for (int k = 0; k < BOMB_NUM; k++)
                {
                    if (m_bombs[k].m_Free)
                    {
                        //爆炸状态设置为非空闲
                        m_bombs[k].m_Free = false;
                        //更新坐标

                        m_bombs[k].m_X = m_enemys[i].m_X;
                        m_bombs[k].m_Y = m_enemys[i].m_Y;
                        break;
                    }
                }
            }

        }
    }



}

void MainScene::drawRecord(QPainter *painter) const
{
    QFont font;
    font.setPixelSize(30);
    font.setFamily("黑体");
    painter->save();
    painter->setPen(Qt::black);
    painter->setFont(font);
    painter->drawText(QRect(349,18,200,50),QString("得分：%1").arg(score));
    painter->drawText(QRect(29,18,200,50),QString("小鸟数目：%1").arg(m_p.m_bulletnum));
}

void MainScene::doGameOver()
{
    if(!gameEnd)
        gameEnd=true;
}
void MainScene::is_stop()
{
    if(m_p.m_bulletnum<=0)
    {

        m_Timer.stop();
gameEnd=true;
              //对话框
//                int isContinue = QMessageBox::question(this, "GAMEOVER", "是否继续游戏",
//                                      QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
//                if(isContinue == QMessageBox::Yes)
//                {
//                    m_p.m_bulletnum = 15;
//                    m_Timer.start();
//                }
//                else
//                {
//                    exit(0);
//                }
    }




}



