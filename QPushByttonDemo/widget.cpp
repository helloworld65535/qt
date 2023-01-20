#include "widget.h"
#include "./ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btn_start_clicked()
{
    QString s=ui->btn_start->text();
    if(s=="启动")
    {
        ui->btn_start->setText("停止");
        ui->btn_start->setFont(QFont("黑体",16));
        ui->btn_start->setIcon(QIcon(":/icon/pause.png"));
        ui->btn_start->setIconSize(QSize(48,48));
    }
    else
    {
        ui->btn_start->setText("启动");
        ui->btn_start->setFont(QFont("黑体",12));
        ui->btn_start->setIcon(QIcon(":/icon/play.png"));
        ui->btn_start->setIconSize(QSize(32,32));
    }
}


void Widget::on_btn_connect_clicked()
{
    QString s=ui->btn_connect->text();
    if(s=="连接")
        {
        ui->btn_connect->setText("断开连接");
        ui->btn_send->setEnabled(true);
    }
    else
    {
        ui->btn_connect->setText("连接");
        ui->btn_send->setEnabled(false);
    }
}


void Widget::on_btn_signal_clicked()
{
    qDebug()<<"clicked";
}


void Widget::on_btn_signal_pressed()
{
    qDebug()<<"pressed";
}


void Widget::on_btn_signal_released()
{
   qDebug()<<"released";
}

