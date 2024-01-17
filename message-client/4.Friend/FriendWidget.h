#ifndef _FRIEND_WIDGET_H_
#define _FRIEND_WIDGET_H_

#include "ui_FriendWidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class FriendWgt; };
QT_END_NAMESPACE

class FriendWgt : public QWidget
{
	Q_OBJECT
public:
	FriendWgt(QWidget* parent = nullptr);
	~FriendWgt();

private:
	Ui::FriendWgt* m_pUi = nullptr;

	/*鼠标事件*/
	QPoint last;                    // 窗口拖动用变量
	bool isPressedWidget = false;   // 鼠标是否按压widget
};

#endif