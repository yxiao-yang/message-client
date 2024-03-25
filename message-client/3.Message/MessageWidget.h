#ifndef _MESSAGE_WIDGET_H_
#define _MESSAGE_WIDGET_H_

#include "ui_MessageWidget.h"
#include "AddFriendWidget.h"
#include "MessageWindowWidget.h"
#include "user.hpp"
#include "message.hpp"
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

	void showAddFriendAns(enApplyType errnoType);

	void getMessageLst();

	void showMessageLst(std::map<std::string, User>& mapTimeUser);

	void showChatMessage(std::vector<Message*> arrMessage);

	void getNewFriendMessage(std::string& message, std::string& friendID, std::string& time, std::string& status);

	void showFriendName(std::string& friendName);

signals:
	void searchUser_Home_Wgt(QString& Userid, QString& Searchid);
	void addFriend_Home_Wgt(QString& userid);
	void getMessageLst_Home_Wgt();
	void getMessageInformation_Home_Wgt(QString& friendUserid);
	void sendFriendMessage_Home_Wgt(QString& msg, QString& userid, QString& friendid);

public slots:
	void searchUser_Message_Friend_Wgt(QString& Userid, QString& Searchid);
	void addFriend_Message_Friend_Wgt(QString& userid);
	void getMessageInformation_Message_Wgt(QString& friendUserid);
	void sendFriendMessage_Message_Wgt(QString& msg, QString& userid, QString& friendid);

private slots:
	void onAddPb();
	void onMessageLstItemWgt(QString& friendUserid);

private:
	Ui::MessageWgt* m_pUi = nullptr;
	QWidget* m_pEmptyWgt = nullptr;
	AddFriendWgt* m_pAddFriendWgt = nullptr;
	MessageWindowWgt* m_pMessageWindowWgt = nullptr;
	std::vector<QListWidgetItem*> m_arrMessageLstItemWgt;
	std::map<std::string, User> m_mapTimeUser;
	QString m_strCurrentFriendId;

	void setSlots();
};

#endif