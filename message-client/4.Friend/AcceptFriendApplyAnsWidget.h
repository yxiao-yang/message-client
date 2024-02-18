#ifndef _ACCEPT_FRIEND_APPLY_ANS_WIDGET_H_
#define _ACCEPT_FRIEND_APPLY_ANS_WIDGET_H_

#include "ui_AcceptFriendApplyAnsWidget.h"
#include "pub.const.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AcceptFriendApplyAnsWgt; };
QT_END_NAMESPACE

class AcceptFriendApplyAnsWgt : public QWidget
{
	Q_OBJECT
public:
	AcceptFriendApplyAnsWgt(QWidget* parent = nullptr);
	~AcceptFriendApplyAnsWgt();

	void setAns(enAcceptApplyType errnoType);

	void mousePressEvent(QMouseEvent* event);       // 鼠标点击
	void mouseMoveEvent(QMouseEvent* event);        // 鼠标移动
	void mouseReleaseEvent(QMouseEvent* event);     // 鼠标释放

signals:
	void updateFriendNotice_FriendNotice_Wgt();

private slots:
	void onAckPb();

private:
	Ui::AcceptFriendApplyAnsWgt* m_pUi = nullptr;

	/*鼠标事件*/
	QPoint last;                    // 窗口拖动用变量
	bool isPressedWidget = false;   // 鼠标是否按压widget
};

#endif
