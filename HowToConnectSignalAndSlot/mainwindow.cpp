#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1. SIGNAL/SLOT
    connect(ui->btn_max,SIGNAL(clicked()),this,SLOT(showMaximized()));

    //2. 函数地址
    connect(ui->btn_normal,&QPushButton::clicked,this,&QMainWindow::showNormal);

    //5.lambda表达式
    connect(ui->btn_set,&QPushButton::clicked,this,[this](){
        this->setWindowTitle("[信号槽链接的5种方式]");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//3. UI设计师界面-转到槽
void MainWindow::on_btn_min_clicked()
{
    this->showMinimized();
}

