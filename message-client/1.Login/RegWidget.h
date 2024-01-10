#ifndef REG_WIDGET_H_
#define REG_WIDGET_H_

#include "ui_RegWidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class RegWgt; };
QT_END_NAMESPACE

class RegWidget : public QWidget
{
	Q_OBJECT

public:
    explicit RegWidget(QWidget* parent = nullptr);
    ~RegWidget();

    // 设置风格
    void setStyle();

    void mousePressEvent(QMouseEvent* event);       // 鼠标点击
    void mouseMoveEvent(QMouseEvent* event);        // 鼠标移动
    void mouseReleaseEvent(QMouseEvent* event);     // 鼠标释放

private slots:
    void onReturnTb();

signals:
    void showLoginWgt();

private:
    Ui::RegWgt* m_pUi = nullptr;
    //LoginWidget* m_pLoginWgt = nullptr;

    /*鼠标事件*/
    QPoint last;                    // 窗口拖动用变量
    bool isPressedWidget = false;   // 鼠标是否按压widget

    // 设置槽函数
    void setSlots();
};

#endif
