#include "wechattest.h"
#include "ui_wechattest.h"
#include "about.h"

WechatTest::WechatTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WechatTest)
{
    QAction action(this);
    action.setShortcuts(QKeySequence::Close);       //退出快捷键

    ui->setupUi(this);
//    ui->horizontalLayoutWidget->resize(this->size());
    ui->lineEdit_x->setVisible(false);
    ui->lineEdit_y->setVisible(false);
    ui->label_x->setVisible(false);
    ui->label_y->setVisible(false);
    ui->textEdit_send->setStyleSheet("font-size : 10px");
    ui->textBrowser->setStyleSheet("font-size : 11px");
    set_radio_id();

}

WechatTest::~WechatTest()
{
    delete ui;
    delete manager;
}
//set radio id
void WechatTest::set_radio_id()
{
    ui->buttonGroup->setId(ui->radio_text, 0);
    ui->buttonGroup->setId(ui->radio_voice, 1);
    ui->buttonGroup->setId(ui->radio_pic, 2);
    ui->buttonGroup->setId(ui->radio_location, 3);
    ui->buttonGroup->setId(ui->radio_follow, 4);
    ui->buttonGroup->setId(ui->radio_unfollow, 5);
    ui->buttonGroup->setId(ui->radio_menu, 6);
}
//deal with radioes click action
void WechatTest::on_radio_text_clicked()
{
    set_content();
    ui->label_content->setText("Content:");
    fetch_content();
    time_t now_time = time(NULL);
    QString detail = "";
    detail = "<xml>\n";
    detail += "<ToUserName><![CDATA[" + to_user_name + "]]></ToUserName>\n";
    detail += "<FromUserName><![CDATA[" + from_user_name + "]]></FromUserName>\n";
    detail += "<CreateTime>" + QString::number(now_time) + "</CreateTime>\n";
    detail += "<MsgType><![CDATA[text]]></MsgType>\n";
    detail += "<Content><![CDATA[" + content + "]]></Content>\n";
    detail += "<MsgId>1234567890123456</MsgId>\n";
    detail += "</xml>";
//    qDebug() << detail;
    ui->textEdit_send->setText(detail);
}

void WechatTest::on_radio_voice_clicked()
{
    set_content();
    ui->label_content->setText("MediaId:");
    fetch_content();
    time_t now_time = time(NULL);
    QString detail = "";
    detail = "<xml>\n";
    detail += "<ToUserName><![CDATA[" + to_user_name + "]]></ToUserName>\n";
    detail += "<FromUserName><![CDATA[" + from_user_name + "]]></FromUserName>\n";
    detail += "<CreateTime>" + QString::number(now_time) + "</CreateTime>\n";
    detail += "<MsgType><![CDATA[voice]]></MsgType>\n";
    detail += "<MediaId><![CDATA[" + content + "]]></MediaId>\n";
    detail += "<Format><![CDATA[Format]]></Format>\n";
    detail += "<MsgId>1234567890123456</MsgId>\n";
    detail += "</xml>";
//    qDebug() << detail;
    ui->textEdit_send->setText(detail);
}

void WechatTest::on_radio_pic_clicked()
{
    set_content();
    ui->label_content->setText("PicUrl:");
    fetch_content();
    time_t now_time = time(NULL);
    QString detail = "";
    detail = "<xml>\n";
    detail += "<ToUserName><![CDATA[" + to_user_name + "]]></ToUserName>\n";
    detail += "<FromUserName><![CDATA[" + from_user_name + "]]></FromUserName>\n";
    detail += "<CreateTime>" + QString::number(now_time) + "</CreateTime>\n";
    detail += "<MsgType><![CDATA[image]]></MsgType>\n";
    detail += "<PicUrl><![CDATA[" + content + "]]></PicUrl>\n";
    detail += "<MediaId><![CDATA[media_id]]></MediaId>\n";
    detail += "<MsgId>1234567890123456</MsgId>\n";
    detail += "</xml>";
    ui->textEdit_send->setText(detail);
}

void WechatTest::on_radio_location_clicked()
{
    set_location();
    fetch_location();
    time_t now_time = time(NULL);
    QString detail = "";
    detail = "<xml>\n";
    detail += "<ToUserName><![CDATA[" + to_user_name + "]]></ToUserName>\n";
    detail += "<FromUserName><![CDATA[" + from_user_name + "]]></FromUserName>\n";
    detail += "<CreateTime>" + QString::number(now_time) + "</CreateTime>\n";
    detail += "<MsgType><![CDATA[location]]></MsgType>\n";
    detail += "<Location_X>" + location_x + "</Location_X>\n";
    detail += "<Location_Y>" + location_y + "</Location_Y>\n";
    detail += "<Scale>20</Scale>\n";
    detail += "<Label><![CDATA[位置信息]]></Label>\n";
    detail += "<MsgId>1234567890123456</MsgId>\n";
    detail += "</xml>";
    ui->textEdit_send->setText(detail);
}

void WechatTest::on_radio_follow_clicked()
{
    disable_some_input();
    fetch_content();
    time_t now_time = time(NULL);
    QString detail = "";
    detail = "<xml>\n";
    detail += "<ToUserName><![CDATA[" + to_user_name + "]]></ToUserName>\n";
    detail += "<FromUserName><![CDATA[" + from_user_name + "]]></FromUserName>\n";
    detail += "<CreateTime>" + QString::number(now_time) + "</CreateTime>\n";
    detail += "<MsgType><![CDATA[event]]></MsgType>\n";
    detail += "<Event><![CDATA[subscribe]]></Event>\n";
    detail += "<MsgId>1234567890123456</MsgId>\n";
    detail += "</xml>";
    ui->textEdit_send->setText(detail);
}

void WechatTest::on_radio_unfollow_clicked()
{
    disable_some_input();
    fetch_content();
    time_t now_time = time(NULL);
    QString detail = "";
    detail = "<xml>\n";
    detail += "<ToUserName><![CDATA[" + to_user_name + "]]></ToUserName>\n";
    detail += "<FromUserName><![CDATA[" + from_user_name + "]]></FromUserName>\n";
    detail += "<CreateTime>" + QString::number(now_time) + "</CreateTime>\n";
    detail += "<MsgType><![CDATA[event]]></MsgType>\n";
    detail += "<Event><![CDATA[unsubscribe]]></Event>\n";
    detail += "<MsgId>1234567890123456</MsgId>\n";
    detail += "</xml>";
    ui->textEdit_send->setText(detail);
}

void WechatTest::on_radio_menu_clicked()
{
    set_content();
    ui->label_content->setText("EventKey:");
    fetch_content();
    time_t now_time = time(NULL);
    QString detail = "";
    detail = "<xml>\n";
    detail += "<ToUserName><![CDATA[" + to_user_name + "]]></ToUserName>\n";
    detail += "<FromUserName><![CDATA[" + from_user_name + "]]></FromUserName>\n";
    detail += "<CreateTime>" + QString::number(now_time) + "</CreateTime>\n";
    detail += "<MsgType><![CDATA[event]]></MsgType>\n";
    detail += "<Event><![CDATA[CLICK]]></Event>\n";
    detail += "<EventKey><![CDATA[" + content + "]]></EventKey>\n";
    detail += "</xml>";
    ui->textEdit_send->setText(detail);
}
//change widgets visiable or not according current method
void WechatTest::set_content()
{
    ui->lineEdit_x->setVisible(false);
    ui->lineEdit_y->setVisible(false);
    ui->label_x->setVisible(false);
    ui->label_y->setVisible(false);
    ui->label_content->setVisible(true);
    ui->lineEdit_content->setVisible(true);
}
void WechatTest::set_location()
{
    ui->label_content->setVisible(false);
    ui->lineEdit_content->setVisible(false);
    ui->lineEdit_x->setVisible(true);
    ui->lineEdit_y->setVisible(true);
    ui->label_x->setVisible(true);
    ui->label_y->setVisible(true);
}
void WechatTest::disable_some_input()
{
    ui->lineEdit_x->setVisible(false);
    ui->lineEdit_y->setVisible(false);
    ui->label_x->setVisible(false);
    ui->label_y->setVisible(false);
    ui->label_content->setVisible(false);
    ui->lineEdit_content->setVisible(false);
}
//fetch the data needed
void WechatTest::fetch_content()
{
    from_user_name = ui->lineEdit_from->text();
    to_user_name = ui->lineEdit_to->text();
    content = ui->lineEdit_content->text().toUtf8();

}
void WechatTest::fetch_location()
{
    from_user_name = ui->lineEdit_from->text();
    to_user_name = ui->lineEdit_to->text();
    location_x = ui->lineEdit_x->text();
    location_y = ui->lineEdit_y->text();
}

//focus on text change, then update some value
void WechatTest::on_lineEdit_content_textChanged()
{
    choose_mode();
}
void WechatTest::on_lineEdit_from_textChanged()
{
    choose_mode();
}
void WechatTest::on_lineEdit_to_textChanged()
{
    choose_mode();
}
void WechatTest::on_lineEdit_x_textChanged()
{
    on_radio_location_clicked();
}
void WechatTest::on_lineEdit_y_textChanged()
{
    on_radio_follow_clicked();
}
//find the current method
void WechatTest::choose_mode()
{
    int check = ui->buttonGroup->checkedId();
    switch(check)
    {
    case 0:
        on_radio_text_clicked();
        break;
    case 1:
        on_radio_voice_clicked();
        break;
    case 2:
        on_radio_pic_clicked();
        break;
    case 3:
        on_radio_location_clicked();
        break;
    case 4:
        on_radio_follow_clicked();
        break;
    case 5:
        on_radio_unfollow_clicked();
        break;
    case 6:
        on_radio_menu_clicked();
        break;
    default:
        break;
    }
}

void WechatTest::on_button_submit_clicked()
{
    ui->button_submit->setEnabled(false);
    QString url = ui->lineEdit_url->text();
    QString data = ui->textEdit_send->toPlainText().replace(QString("\n"), QString(" "));
    send_request(url, data);
}

void WechatTest::on_button_clear_clicked()
{
    ui->textBrowser->clear();
}

void WechatTest::send_request(QString url, QString data)
{
    QUrl post_url(url);
    QByteArray append(data.toUtf8());
    manager = new QNetworkAccessManager(this);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(finishedSlot(QNetworkReply*)));

    QNetworkRequest request(post_url);
    request.setHeader(QNetworkRequest::ContentLengthHeader, QVariant( qulonglong(append.size()) ));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant( QString("text/xml") ));
    manager->post(request, append);
}

//post finish slot
void WechatTest::finishedSlot(QNetworkReply *reply)
{
    // Reading attributes of the reply
    // e.g. the HTTP status code
    QVariant statusCodeV =
         reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    // Or the target URL if it was a redirect
    QVariant redirectionTargetUrl =
         reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    QByteArray bytes = reply->readAll();
    QString string = QString::fromUtf8(bytes);
    ui->textBrowser->append("----------------------------------------------------------------------------------------------------------------------------------------------");
    ui->textBrowser->append(string);
    reply->deleteLater();
//    if(manager != NULL) {
//        delete manager;
//        manager = NULL;
//    }
    ui->button_submit->setEnabled(true);
}


void WechatTest::on_toolButton_clicked()
{
    About *my_about = new About();
    my_about->show();
}
