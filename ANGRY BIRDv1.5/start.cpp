#include "start.h"

start::start(QWidget *parent) : QWidget(parent)
{
    //this->parent=parent;
     this->setFixedSize(480,700);
     this->setWindowTitle("ANGRY BIRD");//窗口标题
     this->setWindowIcon(QIcon("img/bird.png"));//窗口图标

     //背景
     QPalette palette;//设置背景
     //this->setAutoFillBackground(true);
     palette.setBrush(QPalette::Background,QBrush(QPixmap("img/background.png")));
     this->setPalette(palette);
    this->startbtn=new QPushButton(this);//开始按钮
    this->startbtn->setIcon(QIcon("img/bird.png"));
    this->startbtn->setIconSize(QSize(350,150));
    this->startbtn->setFlat(true);//透明
    this->setFocusPolicy(Qt::NoFocus);

    this->vboxlayout=new QVBoxLayout(this);//创建垂直布局变量，使开始按钮置于窗口底部中央
    this->vboxlayout->addWidget(startbtn);
    this->vboxlayout->setAlignment(Qt::AlignBottom);
    this->connect(startbtn,SIGNAL(clicked()),this,SLOT(startbut()));

}
void start::startbut()
{
    this->hide();
    m=new MainScene;
    m->show();
}
