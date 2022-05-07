#ifndef MAINSCENE_H
#define MAINSCENE_H
#include"plane.h"
#include <QWidget>
#include<QPainter>
#include "map.h"
#include<QTimer>
#include<QMouseEvent>
#include"bullet.h"
#include"enemy.h"
#include"boom.h"
#include"plane.h"
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
    //猪出场
    void enemyToScene();

    //
    enemy m_enemys[ENEMY_NUM];

    //出场间隔记录
    int m_recorder;
    //爆炸函数
    void collisionDetection();
    //爆炸
    boom m_bombs[BOMB_NUM];

    void drawRecord(QPainter *painter)const;
    void drawEnd(QPainter *painter) const;

    void doGameOver();

    //得分
    int score;
    int m_hp;

    bool gameEnd;
    QTimer time;
    void is_stop();

};

#endif // MAINSCENE_H
