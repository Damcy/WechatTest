#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}

void About::on_pushButton_2_clicked()
{
    this->close();
}

void About::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("http://me.alipay.com/damcy"));
}

void About::on_pushButton_3_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/Damcy/WechatTest.git"));
}
