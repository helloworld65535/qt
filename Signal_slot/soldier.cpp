#include "soldier.h"

#include <QDebug>

Soldier::Soldier(QObject *parent)
    : QObject{parent}
{

}

void Soldier::fight(QString s)
{
    qDebug() << "Fight for"<<s;
}

void Soldier::escaped()
{
    qDebug() << "I`m afraid of death. Escaped!";
}

void Soldier::fight()
{
    qDebug()<<"fight";
}
