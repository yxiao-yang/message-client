#ifndef _ADD_FRIEND_ANS_WIDGET_H_
#define _ADD_FRIEND_ANS_WIDGET_H_

#include "ui_AddFriendAnsWidget.h"
#include "pub.const.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AddFriendAnsWgt; };
QT_END_NAMESPACE

class AddFriendAnsWgt : public QWidget
{
	Q_OBJECT
public:
	AddFriendAnsWgt(QWidget* parent = nullptr);
	~AddFriendAnsWgt();

	void setAns(enApplyType errnoType);

	void mousePressEvent(QMouseEvent* event);       // 鼠标点击
	void mouseMoveEvent(QMouseEvent* event);        // 鼠标移动
	void mouseReleaseEvent(QMouseEvent* event);     // 鼠标释放

private slots:
	void onAckPb();

private:
	Ui::AddFriendAnsWgt* m_pUi = nullptr;

	/*鼠标事件*/
	QPoint last;                    // 窗口拖动用变量
	bool isPressedWidget = false;   // 鼠标是否按压widget
};

#endif
