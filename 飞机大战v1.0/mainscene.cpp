#include "mainscene.h"
#include "config.h"
#include<QIcon>
#include<QPainter>
#include<QTimer>
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

}
void MainScene::paintEvent(QPaintEvent *event)

{

    QPainter painter(this);
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
            painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

}
