#ifndef START_H
#define START_H
#include"mainscene.h"
#include <QWidget>
#include<QPushButton>
#include<QIcon>
#include<QVBoxLayout>
class start : public QWidget
{
    Q_OBJECT
    QPushButton *startbtn;
    QVBoxLayout *vboxlayout;
   MainScene *m;
public:
    explicit start(QWidget *parent = nullptr);

signals:

public slots:
    void startbut();

};

#endif // START_H
