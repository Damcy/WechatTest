#include "wechattest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WechatTest w;
    w.show();

    return a.exec();
}
