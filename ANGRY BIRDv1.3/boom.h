#ifndef BOOM_H
#define BOOM_H
#include"config.h"
#include"QPixmap"
#include"QVector"
#include<QSound>
class boom
{
public:
    boom();
    void updateInfo();
public:
    QVector<QPixmap>m_pixArr;

    int m_X;
    int m_Y;
    bool m_Free;
    int m_recorder;
    int m_index;
};

#endif // BOOM_H
