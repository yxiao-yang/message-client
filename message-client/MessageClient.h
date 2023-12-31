#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MessageClient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MessageClientClass; };
QT_END_NAMESPACE

class MessageClient : public QMainWindow
{
    Q_OBJECT

public:
    MessageClient(QWidget *parent = nullptr);
    ~MessageClient();

private:
    Ui::MessageClientClass *ui;
};
