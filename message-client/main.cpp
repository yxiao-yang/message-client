#include "MessageClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MessageClient w;
    w.show();
    return a.exec();
}
