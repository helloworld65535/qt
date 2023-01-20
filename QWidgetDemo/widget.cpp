#include "widget.h"
#include "./ui_widget.h"

#include "subwidget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

#if 0
    //未指定父窗口，这个窗口就是独立的窗口
    //需要调用show方法来将其显示
    SubWidget *subwidget1=new SubWidget();
    subwidget1->setWindowTitle("subwidget1");
    subwidget1->show();

    //指定了父窗口，这个窗口就是内嵌窗口
    //不需要调用show方法来将其显示，因为其父窗口显示时，会自动显示子窗口
    SubWidget *subwidget2=new SubWidget(this);
    subwidget2->setWindowTitle("subwidget2");
#endif
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_getsize_clicked()
{
    qDebug() << "------------------------";
    QRect rect = this->geometry();
    qDebug() << "左上：" << rect.topLeft();
    qDebug() << "右上：" << rect.topRight();
    qDebug() << "左下：" << rect.bottomLeft();
    qDebug() << "右下：" << rect.bottomRight();
    qDebug() << "宽：" << rect.width();
    qDebug() << "高：" << rect.height();
}

void Widget::on_btn_setsize_clicked()
{
    this->resize(400, 400);
}

void Widget::on_btn_setfixdsize_clicked()
{
    this->setFixedSize(500, 500);
}
void Widget::on_btn_setminsize_clicked()
{
    this->setMinimumSize(300, 300);
}

void Widget::on_btn_setmaxsize_clicked()
{
    this->setMaximumSize(600, 600);
}

void Widget::on_btn_move_clicked()
{
    this->move(0,0);
}
void Widget::on_btn_settitle_clicked()
{
    this->setWindowTitle("DemoWidget");
}

void Widget::on_btn_seticon_clicked()
{
    this->setWindowIcon(QIcon(":/icon/qt.webp"));
}

