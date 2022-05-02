#include "boom.h"
#include<QString>
boom::boom()
{
  //初始化图片
    for(int i=1;i<=BOMB_MAX;i++)
    {
        QString str=QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));

    }
    m_X=0;
    m_Y=0;
    m_Free=true;
    m_index=0;
    m_recorder=0;

}
void boom::updateInfo(){

    if(m_Free)
    {
        return;
    }
    m_recorder++;
    if(m_recorder<BOMB_INTERVAL)
    {
        return;
    }
    m_recorder=0;
    m_index++;
    if(m_index>BOMB_MAX-1)
    {

        m_index=0;
        m_Free=true;
    }


}
