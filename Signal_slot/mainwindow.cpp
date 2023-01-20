#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_max, SIGNAL(clicked()), this, SLOT(showMaximized()));
    connect(ui->btn_normal, SIGNAL(clicked()), this, SLOT(showNormal()));
    connect(ui->btn_min, SIGNAL(clicked()), this, SLOT(showMinimized()));
    connect(ui->btn_close, SIGNAL(clicked()), this, SLOT(close()));

#if 0   
/* 连接重载的信号和槽，方法1 QT4 */ 
    // 1、创建两个类的实例
    Commander commander;
    Soldier soldier;

    // 2、建立信号和信号槽的连接
    connect(&commander, SIGNAL(go()), &soldier, SLOT(fight()));
    connect(&commander, SIGNAL(go(QString)), &soldier, SLOT(fight(QString)));
    // 3、发送信号 emit可加可不加
    // 当你想用第三方信号/槽机制使用Qt信号和槽时，使用这个宏来替换发出信号的emit关键字。
    // 当.pro文件中的CONFIG变量指定了no_keywords时，通常使用宏，但即使没有指定no_keywords，也可以使用宏。
    emit commander.go();
    /* emit */ commander.go("freedom");
#endif
#if 0
    连接重载的信号和槽，方法2 QT5
    Commander commander;
    Soldier soldier;

    // 没有同名的信号和槽时，可以直接这样写。因为不存在二义性
    //  connect(&commander, &Commander::go(), soldier, &Soldier::fight());

    void (Commander::*pgo)() = &Commander::go;
    void (Soldier::*pfight)() = &Soldier::fight;
    connect(&commander, pgo, &soldier, pfight);

    void (Commander::*pgoQString)(QString) = &Commander::go;
    void (Soldier::*pfightQString)(QString) = &Soldier::fight;
    connect(&commander, pgoQString, &soldier, pfightQString);

    /* //本质上就是进行一个强制类型转换
        connect(&commander,
                (void(Commander::*)(QString)) & Commander::go,
                &soldier,
                (void(Soldier::*)(QString)) & Soldier::fight);
     */

    emit commander.go();
    /* emit */ commander.go("freedom");
#endif
#if 0
    /* 一个信号连接多个槽 */
    Commander commander;
    Soldier soldier1, soldier2;

    connect(&commander, SIGNAL(go()), &soldier1, SLOT(fight()));
    connect(&commander, SIGNAL(go()), &soldier2, SLOT(escaped()));

    emit commander.go();
#endif
#if 0
    /* 多个信号连接一个槽 */
    Commander commander;
    Soldier soldier;

    connect(&commander, SIGNAL(go()), &soldier, SLOT(fight()));
    connect(&commander, SIGNAL(Move()), &soldier, SLOT(fight()));

    emit commander.go();
    emit commander.Move();
#endif
#if 0
    /* 信号连接信号 */

    /* 局部变量在本构造函数结束后释放 ，所以在MainWindow类中私有声明*/
    pcommander = new Commander;
    psoldier = new Soldier;

    connect(ui->btn_action, &QPushButton::clicked,pcommander, &Commander::Move);
    connect(pcommander, SIGNAL(Move()), psoldier, SLOT(fight()));
#endif
#if 1
    /* disconnect 用于断开信号和槽之间已经建立的连接。 */
    Commander commander;
    Soldier soldier;
    connect(&commander,
            (void(Commander::*)()) & Commander::go,
            &soldier,
            (void(Soldier::*)()) & Soldier::fight);
    connect(&commander,
            (void(Commander::*)(QString)) & Commander::go,
            &soldier,
            (void(Soldier::*)(QString)) & Soldier::fight);

    emit commander.go();
    // 断开所有到commander信号上的槽函数
    commander.disconnect();
    emit commander.go("freedom");
    
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}
