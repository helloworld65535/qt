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
    void on_btn_getsize_clicked();

    void on_btn_move_clicked();

    void on_btn_setsize_clicked();

    void on_btn_settitle_clicked();

    void on_btn_setfixdsize_clicked();

    void on_btn_setminsize_clicked();

    void on_btn_setmaxsize_clicked();

    void on_btn_seticon_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
