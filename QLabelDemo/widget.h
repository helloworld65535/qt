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
    void on_btn_gettext_clicked();

    void on_btn_settext_clicked();

    void on_btn_left_clicked();

    void on_btn_center_clicked();

    void on_btn_right_clicked();

    void on_btn_n_clicked();

    void on_btn_y_clicked();

    void on_btn_next_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
