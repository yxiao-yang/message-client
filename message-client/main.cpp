#include "Service.h"
#include "ConnectServer.h"
#include <QtWidgets>
#include <QTextCodec>
#include <QDebug>

#pragma execution_character_set("utf-8") 

int main(int argc, char *argv[])
{
    // ����̨�������
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    SetConsoleOutputCP(65001);

    QApplication a(argc, argv);
    Service::getInstance()->showLoginWgt();

    // ���ӷ�����
    ConnectServer::getInstance()->connectServer();

    return a.exec();
}
