#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    std::srand(std::time(nullptr));
    secret_number = std::rand()%10 +1;
    qDebug()<<"Secrect Number generated: "<<QString::number(secret_number);
    ui->startoverButton->setDisabled(true);
    ui->msgLabel->setText("");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_guessButton_clicked()
{
    guess_number = ui->numberSpinBox->value();
    qDebug()<<"User guessed: "<<QString::number(guess_number);
    if(guess_number==secret_number){
        ui->msgLabel->setText("Congratulation, number is "+ QString::number(guess_number));
        ui->guessButton->setDisabled(true);
        ui->startoverButton->setDisabled(false);
    }
    else{
        if(secret_number > guess_number) ui->msgLabel->setText("Number is lower than secret number!!");
        else if(secret_number< guess_number) ui->msgLabel->setText("Number is bigger than secret number!!");
    }

}


void Widget::on_startoverButton_clicked()
{
    qDebug()<<"Start Over button clicked!!";
    ui->guessButton->setDisabled(false);
    ui->startoverButton->setDisabled(true);
    ui->numberSpinBox->setValue(1);
    secret_number = rand()%10+1;
    qDebug()<<"Secrect Number generated: "<<QString::number(secret_number);
    ui->msgLabel->setText("");
}

