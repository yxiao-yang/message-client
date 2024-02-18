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

	void mousePressEvent(QMouseEvent* event);       // �����
	void mouseMoveEvent(QMouseEvent* event);        // ����ƶ�
	void mouseReleaseEvent(QMouseEvent* event);     // ����ͷ�

signals:
	void updateFriendNotice_FriendNotice_Wgt();

private slots:
	void onAckPb();

private:
	Ui::AcceptFriendApplyAnsWgt* m_pUi = nullptr;

	/*����¼�*/
	QPoint last;                    // �����϶��ñ���
	bool isPressedWidget = false;   // ����Ƿ�ѹwidget
};

#endif
