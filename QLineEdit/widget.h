#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btn_normal_clicked();

    void on_btn_password_clicked();

    void on_btn_noecho_clicked();

    void on_btn_pe_clicked();

    void on_btn_out1_clicked();

    void on_btn_l_clicked();

    void on_btn_c_clicked();

    void on_btn_r_clicked();


    void on_btn_readwrite_clicked();

    void on_btn_readonly_clicked();

    void on_btn_disable_clicked();

    void on_btn_enable_clicked();

    void on_btn_out3_clicked();

    void on_btn_masknone_clicked();

    void on_btn_maskphone_clicked();

    void on_btn_maskkey_clicked();

    void on_le_51_textChanged(const QString &arg1);

    void on_le_52_textChanged(const QString &arg1);

    void on_le_54_editingFinished();

    void on_le_55_editingFinished();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
