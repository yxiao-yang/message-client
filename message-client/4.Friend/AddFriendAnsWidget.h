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

	void mousePressEvent(QMouseEvent* event);       // �����
	void mouseMoveEvent(QMouseEvent* event);        // ����ƶ�
	void mouseReleaseEvent(QMouseEvent* event);     // ����ͷ�

private slots:
	void onAckPb();

private:
	Ui::AddFriendAnsWgt* m_pUi = nullptr;

	/*����¼�*/
	QPoint last;                    // �����϶��ñ���
	bool isPressedWidget = false;   // ����Ƿ�ѹwidget
};

#endif
