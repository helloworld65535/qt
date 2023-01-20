#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    pButtonGroupGender=new QButtonGroup(this);
    pButtonGroupGender->addButton(ui->rb4_m);
    pButtonGroupGender->addButton(ui->rb4_f);
    pButtonGroupEdu=new QButtonGroup(this);
    pButtonGroupEdu->addButton(ui->rb4_bs);
    pButtonGroupEdu->addButton(ui->rb4_ss);
    pButtonGroupEdu->addButton(ui->rb4_bk);
    pButtonGroupEdu->addButton(ui->rb4_qt);



    connect(ui->rb4_m,&QRadioButton::clicked,this,&Widget::OnRadioButtonClicked);
    connect(ui->rb4_f,&QRadioButton::clicked,this,&Widget::OnRadioButtonClicked);
    connect(ui->rb4_bs,&QRadioButton::clicked,this,&Widget::OnRadioButtonClicked);
    connect(ui->rb4_ss,&QRadioButton::clicked,this,&Widget::OnRadioButtonClicked);
    connect(ui->rb4_bk,&QRadioButton::clicked,this,&Widget::OnRadioButtonClicked);
    connect(ui->rb4_qt,&QRadioButton::clicked,this,&Widget::OnRadioButtonClicked);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString s;
    if(ui->rb3_m->isChecked())
    {
        s+=ui->rb3_m->text();

    }else if(ui->rb3_f->isChecked())
    {
        s+=ui->rb3_f->text();
    }

    if(ui->rb3_bs->isChecked())
    {
        s+=ui->rb3_bs->text();
    }
    else if(ui->rb3_ss->isChecked())
    {
        s+=ui->rb3_ss->text();
    }
    if(ui->rb3_bk->isChecked())
    {
        s+=ui->rb3_bk->text();
    }
    if(ui->rb3_qt->isChecked())
    {
        s+=ui->rb3_qt->text();
    }
    ui->lineEdit1->setText(s);
}


//void Widget::on_pushButton_2_clicked()
//{
//    QString s;
//    if(ui->rb4_m->isChecked())
//    {
//        s+=ui->rb4_m->text();

//    }else if(ui->rb4_f->isChecked())
//    {
//        s+=ui->rb4_f->text();
//    }

//    if(ui->rb4_bs->isChecked())
//    {
//        s+=ui->rb4_bs->text();
//    }
//    else if(ui->rb4_ss->isChecked())
//    {
//        s+=ui->rb4_ss->text();
//    }
//    if(ui->rb4_bk->isChecked())
//    {
//        s+=ui->rb4_bk->text();
//    }
//    if(ui->rb4_qt->isChecked())
//    {
//        s+=ui->rb4_qt->text();
//    }
//    ui->lineEdit_2->setText(s);
//}

void Widget::OnRadioButtonClicked()
{
    QString s;
    if(ui->rb4_m->isChecked())
    {
        s+=ui->rb4_m->text();

    }else if(ui->rb4_f->isChecked())
    {
        s+=ui->rb4_f->text();
    }

    if(ui->rb4_bs->isChecked())
    {
        s+=ui->rb4_bs->text();
    }
    else if(ui->rb4_ss->isChecked())
    {
        s+=ui->rb4_ss->text();
    }
    if(ui->rb4_bk->isChecked())
    {
        s+=ui->rb4_bk->text();
    }
    if(ui->rb4_qt->isChecked())
    {
        s+=ui->rb4_qt->text();
    }
    ui->lineEdit_2->setText(s);
}

