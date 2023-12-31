#include "MessageClient.h"

MessageClient::MessageClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MessageClientClass())
{
    ui->setupUi(this);
}

MessageClient::~MessageClient()
{
    delete ui;
}
