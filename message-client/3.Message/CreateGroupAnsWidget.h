#ifndef _CREATE_GROUP_ANS_WIDGET_H_
#define _CREATE_GROUP_ANS_WIDGET_H_

#include "ui_CreateGroupAnsWidget.h"
#include "pub.const.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CreateGroupAnsWgt; };
QT_END_NAMESPACE

class CreateGroupAnsWgt : public QWidget
{
	Q_OBJECT
public:
	CreateGroupAnsWgt(QWidget* parent = nullptr);
	~CreateGroupAnsWgt();

	void setAns();

	void mousePressEvent(QMouseEvent* event);       // 鼠标点击
	void mouseMoveEvent(QMouseEvent* event);        // 鼠标移动
	void mouseReleaseEvent(QMouseEvent* event);     // 鼠标释放

private slots:
	void onAckPb();

private:
	Ui::CreateGroupAnsWgt* m_pUi = nullptr;

	/*鼠标事件*/
	QPoint last;                    // 窗口拖动用变量
	bool isPressedWidget = false;   // 鼠标是否按压widget
};

#endif
