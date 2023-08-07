#include "widget.h"
#include "ui_widget.h"
#include <iostream>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    if(money+diff <0){

        mb.information(this,"Error","잔액부족");
        return;
    }
    money += diff;
    ui->lcdNumber->display(money);
    if(money >=100){
        ui->pbCoffee->setEnabled(true);
    }
    else{
        ui->pbCoffee->setEnabled(false);
    }
    if(money>=150){
            ui->pbTea->setEnabled(true);
        }
    else {
            ui->pbTea->setEnabled(false);
    }
    if(money >= 200){
            ui->pbMilk->setEnabled(true);
        }
    else{
            ui->pbMilk->setEnabled(false);
        }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pb100_clicked()
{
   changeMoney(100);
}

void Widget::on_pbCoffee_clicked()
{
   changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}





void Widget::on_pbReset_clicked()
{
    std::cout <<"?"<<std::endl;
    int coin500, coin100, coin50, coin10;
    coin500 = money / 500;
    coin100 = money % 500 / 100;
    coin50 = money % 500 % 100 / 50;
    coin10 = money % 500 % 100 % 50 / 10;
    mb.information(this,"거스름돈",QString("500원: %1\n 100원: %2\n 50원: %3\n 10원: %4\n").arg(coin500).arg(coin100).arg(coin50).arg(coin10)); //명시안하면 안적음
    changeMoney(-money);
}




