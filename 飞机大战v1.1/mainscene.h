#ifndef MAINSCENE_H
#define MAINSCENE_H
#include"plane.h"
#include <QWidget>
#include "map.h"
#include<QTimer>
#include<QMouseEvent>
#include"bullet.h"
class MainScene : public QWidget
{
    Q_OBJECT
    QTimer m_Timer;
public:
    MainScene(QWidget *parent = 0);
    ~MainScene();
    void initScene();
    //启动游戏
    void playgame();
    //更新坐标
    void updatePosition();
    //绘制地图
    void paintEvent(QPaintEvent *event);
    map m_map;
    plane m_p;
    void mouseMoveEvent(QMouseEvent *event);
    //ceshi

};

#endif // MAINSCENE_H
