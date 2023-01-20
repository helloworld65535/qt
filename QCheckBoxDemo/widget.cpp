#include "widget.h"
#include "./ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->checkBox_pg,&QCheckBox::stateChanged,this,&Widget::onStateChanged);
    connect(ui->checkBox_l,&QCheckBox::stateChanged,this,&Widget::onStateChanged);
    connect(ui->checkBox_xj,&QCheckBox::stateChanged,this,&Widget::onStateChanged);
    connect(ui->checkBox_tz,&QCheckBox::stateChanged,this,&Widget::onStateChanged);



}

Widget::~Widget()
{
    delete ui;
}

void Widget::onStateChanged()
{
    QString s;

    int ck_pg=(ui->checkBox_pg->isChecked());
    int ck_xj=(ui->checkBox_xj->isChecked());
    int ck_l=(ui->checkBox_l->isChecked());
    int ck_tz=(ui->checkBox_tz->isChecked());

    int chk_all=ck_pg+ck_xj+ck_l+ck_tz;
    if(chk_all==4)//全选
    {
        ui->checkBox_all->setCheckState(Qt::Checked);
    }
    else if(chk_all==0)
    {
        ui->checkBox_all->setCheckState(Qt::Unchecked);

    }
    else
    {
        ui->checkBox_all->setCheckState(Qt::PartiallyChecked);
    }
    if(ck_pg)s+=ui->checkBox_pg->text();
    if(ck_xj)s+=ui->checkBox_xj->text();
    if(ck_l)s+=ui->checkBox_l->text();
    if(ck_tz)s+=ui->checkBox_tz->text();
    ui->lineEdit->setText(s);
}


void Widget::on_checkBox_all_clicked()
{
    ui->checkBox_all->setTristate(false);
    if( ui->checkBox_all->isChecked())
    {
        ui->checkBox_pg->setChecked(true);
        ui->checkBox_xj->setChecked(true);
        ui->checkBox_l->setChecked(true);
        ui->checkBox_tz->setChecked(true);
    }
    else
    {
        ui->checkBox_pg->setChecked(false);
        ui->checkBox_xj->setChecked(false);
        ui->checkBox_l->setChecked(false);
        ui->checkBox_tz->setChecked(false);
    }
}

