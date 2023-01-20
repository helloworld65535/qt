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
    void on_btn_start_clicked();

    void on_btn_connect_clicked();

    void on_btn_signal_clicked();

    void on_btn_signal_pressed();

    void on_btn_signal_released();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
