#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeEnable();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    changeEnable();
}

void Widget::changeEnable(){
    ui->pbCoffee->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=200);
    ui->pbTang->setEnabled(money>=300);
    ui->pbReset->setEnabled(money!=0);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;

    int a = money / 500;
    int b = (money % 500) / 100;
    int c = (money % 100) / 50;
    int d = (money % 50) / 10;

    QString a_str = QString::number(a);
    QString b_str = QString::number(b);
    QString c_str = QString::number(c);
    QString d_str = QString::number(d);

    QString result = "500 won : " + a_str + " / 100 won : " + b_str + " / 50 won : " + c_str + " / 10 won : " + d_str;
    mb.information(nullptr, "Reset Money", result);
    changeMoney(-money);

}

