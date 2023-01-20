#include "widget.h"
#include "./ui_widget.h"

#include <QDebug>
#include <QMessageBox>
#include <QTime>
#include <QPixmap>


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


void Widget::on_btn_gettext_clicked()
{
    QMessageBox::information(this,"标签演示",ui->lb_1->text());
    qDebug()<<ui->lb_1->text();
}


void Widget::on_btn_settext_clicked()
{
    ui->lb_1->setText(QTime::currentTime().toString());
}



void Widget::on_btn_left_clicked()
{
    ui->lb_2->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
}


void Widget::on_btn_center_clicked()
{
    ui->lb_2->setAlignment(Qt::AlignCenter|Qt::AlignVCenter);
}


void Widget::on_btn_right_clicked()
{
    ui->lb_2->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
}


void Widget::on_btn_n_clicked()
{
    ui->lb_3->setWordWrap(false);
}


void Widget::on_btn_y_clicked()
{
    ui->lb_3->setWordWrap(true);
}

int index=0;
void Widget::on_btn_next_clicked()
{
    if(index==0){
        ui->lb_4->setPixmap(QPixmap(":/icon/pause.png"));
        index++;
    }
    else if(index==1){

        ui->lb_4->setPixmap(QPixmap(":/icon/stop.png"));
        index++;
    }
    else
    {
        ui->lb_4->setPixmap(QPixmap(":/icon/play.png"));
        index=0;
    }
}

