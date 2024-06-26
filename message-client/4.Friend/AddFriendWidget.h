#ifndef _ADD_FRIEND_WIDGET_H_
#define _ADD_FRIEND_WIDGET_H_

#include "ui_AddFriendWidget.h"
#include "SearchResWidget.h"
#include "AddFriendAnsWidget.h"
#include "user.hpp"
#include "pub.const.h"
#include <QWidget>
#include <QScrollArea>

QT_BEGIN_NAMESPACE
namespace Ui { class AddFriendWgt; };
QT_END_NAMESPACE

class AddFriendWgt : public QWidget
{
	Q_OBJECT
public:
	AddFriendWgt(QWidget* parent = nullptr);
	~AddFriendWgt();

	// 添加好友界面 展示搜索结果
	void showSearchRes(std::vector<User>& arrUser);

	// 弹窗
	void showAddFriendAns(enApplyType errnoType);

signals:
	void searchUser_Message_Friend_Wgt(QString& Userid, QString& Searchid);
	void addFriend_Message_Friend_Wgt(QString& userid);

public slots:
	void addFriend_AddFriend_Wgt(QString& userid, QString& username);

private slots:
	void onTbSearch();

private:
	Ui::AddFriendWgt* m_pUi = nullptr;
	QVBoxLayout* m_pUserLayout = nullptr;

	std::vector<SearchResWgt*> m_arrSearchResWgt;
	AddFriendAnsWgt* m_pAddFriendAnsWgt = nullptr;

	void setSlots();
};

#endif