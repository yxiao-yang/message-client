#ifndef _LOGIN_WIDGET_H_
#define _LOGIN_WIDGET_H_

#include "ui_LoginWidget.h"
#include "RegWidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWgt; };
QT_END_NAMESPACE

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

    // 设置风格
    void setStyle();

    void mousePressEvent(QMouseEvent* event);       // 鼠标点击
    void mouseMoveEvent(QMouseEvent* event);        // 鼠标移动
    void mouseReleaseEvent(QMouseEvent* event);     // 鼠标释放

signals:
    void showRegWgt_LoginService(); // 展示注册窗口
    void loginHome_LoginService(QString& Userid, QString& Password);  // 登录业务

private slots:
    void onTbMinus();       // 最小化窗口
    void onTbClose();       // 关闭窗口
    void onPbReg();         // 注册按钮
    void onPbLogin();       // 登录按钮

private:
    Ui::LoginWgt* m_pUi = nullptr;
    //RegWidget* m_pRegWgt = nullptr;

    /*鼠标事件*/
    QPoint last;                    // 窗口拖动用变量
    bool isPressedWidget = false;   // 鼠标是否按压widget

    // 设置槽函数
    void setSlots();
};

#endif
