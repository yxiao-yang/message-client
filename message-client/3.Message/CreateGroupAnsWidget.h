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

	void mousePressEvent(QMouseEvent* event);       // �����
	void mouseMoveEvent(QMouseEvent* event);        // ����ƶ�
	void mouseReleaseEvent(QMouseEvent* event);     // ����ͷ�

private slots:
	void onAckPb();

private:
	Ui::CreateGroupAnsWgt* m_pUi = nullptr;

	/*����¼�*/
	QPoint last;                    // �����϶��ñ���
	bool isPressedWidget = false;   // ����Ƿ�ѹwidget
};

#endif
