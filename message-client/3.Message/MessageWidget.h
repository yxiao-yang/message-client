#ifndef _MESSAGE_WIDGET_H_
#define _MESSAGE_WIDGET_H_

#include "ui_MessageWidget.h"
#include "AddFriendWidget.h"
#include "user.hpp"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MessageWgt; };
QT_END_NAMESPACE

class MessageWgt : public QWidget
{
	Q_OBJECT
public:
	MessageWgt(QWidget* parent = nullptr);
	~MessageWgt();

	void switchMessageSWgt(int idx);

	// ��Ӻ��ѽ��� չʾ�������
	void showSearchRes(std::vector<User>& arrUser);

signals:
	void searchUser_Home_Wgt(QString& Userid, QString& Searchid);

public slots:
	void searchUser_Message_Friend_Wgt(QString& Userid, QString& Searchid);

private:
	Ui::MessageWgt* m_pUi = nullptr;
	AddFriendWgt* m_pAddFriendWgt = nullptr;

	void setSlots();
};

#endif