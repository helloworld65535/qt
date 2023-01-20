#ifndef SOLDIER_H
#define SOLDIER_H

#include <QObject>

class Soldier : public QObject
{
    Q_OBJECT
public:
    explicit Soldier(QObject *parent = nullptr);

signals:

//槽函数的返回值和参数，要和信号保持一致
public slots:
    void fight();
    void fight(QString s);
    //为士兵添加一个逃跑的槽函数
    void escaped();
};

#endif // SOLDIER_H
