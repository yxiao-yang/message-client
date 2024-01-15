#ifndef _REG_SUCCESS_WIDGET_H_
#define _REG_SUCCESS_WIDGET_H_

#include "ui_RegSuccessWidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class RegSuccessWgt; };
QT_END_NAMESPACE

class RegSuccessWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegSuccessWidget(QWidget* parent = nullptr);
    ~RegSuccessWidget();

    // 设置风格
    void setStyle(const std::string& strUserid);

    void mousePressEvent(QMouseEvent* event);       // 鼠标点击
    void mouseMoveEvent(QMouseEvent* event);        // 鼠标移动
    void mouseReleaseEvent(QMouseEvent* event);     // 鼠标释放

private slots:
    void onReturnPb();

signals:
    void showLoginWgt_RegSuccessService();

private:
    Ui::RegSuccessWgt* m_pUi = nullptr;

    /*鼠标事件*/
    QPoint last;                    // 窗口拖动用变量
    bool isPressedWidget = false;   // 鼠标是否按压widget

    // 设置槽函数
    void setSlots();
};

#endif
