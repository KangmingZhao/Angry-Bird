#ifndef MAINSCENE_H
#define MAINSCENE_H
#include"plane.h"
#include <QWidget>
#include "map.h"
#include<QTimer>
#include<QMouseEvent>
#include"bullet.h"
#include"enemy.h"
#include"boom.h"
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
    //敌机出场
    void enemyToScene();

    //敌机数组
    enemy m_enemys[ENEMY_NUM];

    //敌机出场间隔记录
    int m_recorder;
    //爆炸函数
    void collisionDetection();
    //爆炸
    boom m_bombs[BOMB_NUM];
};

#endif // MAINSCENE_H
