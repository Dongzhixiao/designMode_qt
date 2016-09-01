#include "caculate.h"
#include "ui_caculate.h"

#include "signfactory.h"
#include "sign.h"

#include <QMessageBox>

caculate::caculate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::caculate)
{
    ui->setupUi(this);
}

caculate::~caculate()
{
    delete ui;
}

void caculate::on_pushButton_clicked()
{
    if(ui->comboBox_sign->currentText() == "/" && ui->lineEdit_num2->text().toDouble() == 0)
    {
        QMessageBox::warning(this,QString::fromUtf8("错误"),QString::fromUtf8("被除数不能为0"),QMessageBox::Ok);
        return;
    }
    Signfactory sf = Signfactory();
    Sign * s = sf.createSign(ui->comboBox_sign->currentText());
    s->setA(ui->lineEdit_num1->text().toDouble());
    s->setB(ui->lineEdit_num2->text().toDouble());
    ui->lcdNumber_result->display(s->getResult());
}
