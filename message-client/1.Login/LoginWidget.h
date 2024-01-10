#ifndef LOGIN_WIDGET_H
#define LOGIN_WIDGET_H

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

    void mousePressEvent(QMouseEvent* event);       // 鼠标点击
    void mouseMoveEvent(QMouseEvent* event);        // 鼠标移动
    void mouseReleaseEvent(QMouseEvent* event);     // 鼠标释放

private slots:
    void onTbMinus();   // 最小化窗口
    void onTbClose();   // 关闭窗口
    void onPbReg();     // 注册按钮

signals:
    void showRegWidget();   // 跳转到注册界面

private:
    Ui::LoginWgt *m_pUi;
    RegWidget* m_pRegWgt = nullptr;

    /*鼠标事件*/
    QPoint last;                    // 窗口拖动用变量
    bool isPressedWidget = false;   // 鼠标是否按压widget

    // 设置风格
    void setStyle();

    // 设置槽函数
    void setSlots();
};

#endif
