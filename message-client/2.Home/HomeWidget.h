#ifndef _HOME_WIDGET_H_
#define _HOME_WIDGET_H_

#include "ui_HomeWidget.h"
#include "MessageWidget.h"
#include "FriendWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HomeWgt; };
QT_END_NAMESPACE

class HomeWidget : public QWidget
{
	Q_OBJECT
public:
	HomeWidget(QWidget* parent = nullptr);
	~HomeWidget();

	// 设置风格
	void setStyle();

	void mousePressEvent(QMouseEvent* event);       // 鼠标点击
	void mouseMoveEvent(QMouseEvent* event);        // 鼠标移动
	void mouseReleaseEvent(QMouseEvent* event);     // 鼠标释放

private slots:
	void onTbMinus();       // 最小化窗口
	void onTbClose();       // 关闭窗口

private:
	Ui::HomeWgt* m_pUi = nullptr;
	MessageWgt* m_pMessageWgt = nullptr;
	FriendWgt* m_pFriendWgt = nullptr;

	/*鼠标事件*/
	QPoint last;                    // 窗口拖动用变量
	bool isPressedWidget = false;   // 鼠标是否按压widget
	
	// 设置槽函数
	void setSlots();

};

#endif
