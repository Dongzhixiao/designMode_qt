#include "shopprice.h"
#include "ui_shopprice.h"

#include "cashcontext.h"

#include <QDebug>

shopPrice::shopPrice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shopPrice)
{
    ui->setupUi(this);

    connect(ui->lineEdit_money,SIGNAL(textChanged(QString)),this,SLOT(line_changed(QString)));
    connect(ui->comboBox_strategy,SIGNAL(currentIndexChanged(QString)),this,SLOT(com_changed(QString)));
    ui->comboBox_strategy->setCurrentIndex(0);
}

shopPrice::~shopPrice()
{
    delete ui;
}

void shopPrice::line_changed(const QString &)
{
    CashContext *cc = new CashContext(ui->comboBox_strategy->currentText());
    double result = cc->getResult(ui->lineEdit_money->text().toDouble());
    ui->lineEdit_result->setText(QString::number(result));
    delete cc;
}

void shopPrice::com_changed(const QString & s)
{
    qDebug()<<s;
    CashContext *cc = new CashContext(ui->comboBox_strategy->currentText());
    double result = cc->getResult(ui->lineEdit_money->text().toDouble());
    qDebug()<<result;
    ui->lineEdit_result->setText(QString::number(result));
    delete cc;
}
