#pragma once

#include <QWidget>
#include "ui_LoginWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWgt; };
QT_END_NAMESPACE

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private:
    Ui::LoginWgt *m_pUi;

    // …Ë÷√∑Á∏Ò
    void setStyle();
};
