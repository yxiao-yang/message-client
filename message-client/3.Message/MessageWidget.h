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

	// 添加好友界面 展示搜索结果
	void showSearchRes(std::vector<User>& arrUser);

signals:
	void searchUser_Home_Wgt(QString& Userid, QString& Searchid);
	void addFriend_Home_Wgt(QString& userid);

public slots:
	void searchUser_Message_Friend_Wgt(QString& Userid, QString& Searchid);
	void addFriend_Message_Friend_Wgt(QString& userid);

private slots:
	void onAddPb();

private:
	Ui::MessageWgt* m_pUi = nullptr;
	QWidget* m_pEmptyWgt = nullptr;
	AddFriendWgt* m_pAddFriendWgt = nullptr;

	void setSlots();
};

#endif