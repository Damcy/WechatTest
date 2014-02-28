#ifndef WECHATTEST_H
#define WECHATTEST_H

#include <QWidget>
#include <time.h>
#include <iostream>
#include <QtDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QByteArray>
#include <QAction>

using namespace std;

namespace Ui {
class WechatTest;
}

class WechatTest : public QWidget
{
    Q_OBJECT

public:
    explicit WechatTest(QWidget *parent = 0);
    ~WechatTest();

private slots:
    void on_radio_text_clicked();

    void on_radio_voice_clicked();

    void on_radio_pic_clicked();

    void on_radio_location_clicked();

    void on_radio_follow_clicked();

    void on_radio_unfollow_clicked();

    void on_radio_menu_clicked();

    void on_lineEdit_content_textChanged();

    void on_lineEdit_from_textChanged();

    void on_lineEdit_to_textChanged();

    void on_lineEdit_x_textChanged();

    void on_lineEdit_y_textChanged();

    void on_button_submit_clicked();

    void on_button_clear_clicked();

    void finishedSlot(QNetworkReply *reply);


    void on_toolButton_clicked();

private:
    Ui::WechatTest *ui;
    QString request_url;
    QString from_user_name;
    QString to_user_name;
    QString content;
    QString location_x;
    QString location_y;
    QNetworkAccessManager *manager;


private:
    void set_radio_id();
    void set_content();
    void set_location();
    void disable_some_input();
    void fetch_content();
    void fetch_location();
    void choose_mode();
    void send_request(QString url, QString data);
};

#endif // WECHATTEST_H
