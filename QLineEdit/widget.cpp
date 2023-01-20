#include "widget.h"
#include "./ui_widget.h"

#include <QMessageBox>

#include <QIntValidator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //QIntValidator 类提供确保字符串包含指定范围内有效整数的验证器。
    ui->setupUi(this);
    QIntValidator *qIntValidator=new QIntValidator(this);
    ui->le_51->setValidator(qIntValidator);
    ui->le_52->setValidator(qIntValidator);
    ui->le_54->setValidator(qIntValidator);
    ui->le_55->setValidator(qIntValidator);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btn_normal_clicked()
{
    ui->le_1->clear();
    ui->le_1->setEchoMode(QLineEdit::Normal);
    //设置输入为空时显示的字符串
    ui->le_1->setPlaceholderText("Normal");
}


void Widget::on_btn_password_clicked()
{
    ui->le_1->clear();
    ui->le_1->setEchoMode(QLineEdit::Password);
    //设置输入为空时显示的字符串
    ui->le_1->setPlaceholderText("Password");
}




void Widget::on_btn_noecho_clicked()
{
    ui->le_1->clear();
    ui->le_1->setEchoMode(QLineEdit::NoEcho);
    //设置输入为空时显示的字符串
    ui->le_1->setPlaceholderText("NoEcho");
}


void Widget::on_btn_pe_clicked()
{
    ui->le_1->clear();
    ui->le_1->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    //设置输入为空时显示的字符串
    ui->le_1->setPlaceholderText("PasswordEchoOnEdit");
}


void Widget::on_btn_out1_clicked()
{
    QMessageBox::information(this,"回显模式输出内容",ui->le_1->text());
}


void Widget::on_btn_l_clicked()
{
    ui->le_2->setAlignment(Qt::AlignLeft);
    ui->le_2->setPlaceholderText("AlignLeft");
}


void Widget::on_btn_c_clicked()
{
    ui->le_2->setAlignment(Qt::AlignCenter);
    ui->le_2->setPlaceholderText("AlignCenter");
}


void Widget::on_btn_r_clicked()
{
    ui->le_2->setAlignment(Qt::AlignRight);
    ui->le_2->setPlaceholderText("AlignRight");
}





void Widget::on_btn_readwrite_clicked()
{
    ui->le_3->setReadOnly(false);
    ui->le_3->setPlaceholderText("readwrite");
}


void Widget::on_btn_readonly_clicked()
{
    ui->le_3->setReadOnly(true);
    ui->le_3->setPlaceholderText("readonly");
}


void Widget::on_btn_disable_clicked()
{
    ui->le_3->setEnabled(false);
    ui->le_3->setPlaceholderText("disable");
}


void Widget::on_btn_enable_clicked()
{
    ui->le_3->setEnabled(true);
    ui->le_3->setPlaceholderText("enable");
}


void Widget::on_btn_out3_clicked()
{
    QMessageBox::information(this,"读写控制输出内容",ui->le_3->text());
}


void Widget::on_btn_masknone_clicked()
{
    ui->le_4->setInputMask("");
}



void Widget::on_btn_maskphone_clicked()
{
    // 9    表示要求输入0~9的数字
    // ;    表示格式字符串结束
    // #    表示无输入时显示的字符
    ui->le_4->setInputMask("99999999999;#");
}


void Widget::on_btn_maskkey_clicked()
{
    // >    转换为大写
    // A    代表要求输入英文字母
    ui->le_4->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");
}


void Widget::on_le_51_textChanged(const QString &arg1)
{
    int sum=arg1.toInt()+ui->le_52->text().toInt();
    ui->le_53->setText(QString::number(sum));
}


void Widget::on_le_52_textChanged(const QString &arg1)
{
    int sum=arg1.toInt()+ui->le_51->text().toInt();
    ui->le_53->setText(QString::number(sum));
}


void Widget::on_le_54_editingFinished()
{
    int sum=ui->le_54->text().toInt()-ui->le_55->text().toInt();
    ui->le_56->setText(QString::number(sum));
}


void Widget::on_le_55_editingFinished()
{
    int sum=ui->le_54->text().toInt()-ui->le_55->text().toInt();
    ui->le_56->setText(QString::number(sum));
}

