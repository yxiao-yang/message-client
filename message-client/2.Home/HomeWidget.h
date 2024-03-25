#ifndef _HOME_WIDGET_H_
#define _HOME_WIDGET_H_

#include "ui_HomeWidget.h"
#include "MessageWidget.h"
#include "FriendWidget.h"
#include "ChatAiWidget.h"
#include "user.hpp"
#include "message.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class HomeWgt; };
QT_END_NAMESPACE

class HomeWidget : public QWidget
{
	Q_OBJECT
public:
	HomeWidget(QWidget* parent = nullptr);
	~HomeWidget();

	// ��Ӻ��ѽ��� չʾ�������
	void showSearchRes(std::vector<User>& arrUser);

	void showAddFriendAns(enApplyType errnoType);

	void showFriendNotice(std::vector<User>& arrApplyUser, std::vector<User>& arrAppliedUser, std::vector<std::string>& arrApplyTime, std::vector<std::string>& arrAppliedTime);

	void showAcceptFriendApplyAns(enAcceptApplyType errnoType);

	void showFriendship(std::vector<User>& arrUser);

	void showMessageWgt();

	void showMessageLst(std::map<std::string, User>& mapTimeUser);

	void showChatMessage(std::vector<Message*> arrMessage);

	void getNewFriendMessage(std::string& message, std::string& friendID, std::string& time, std::string& status);

	void getNewMessageLst();

	// ���÷��
	void setStyle();

	void mousePressEvent(QMouseEvent* event);       // �����
	void mouseMoveEvent(QMouseEvent* event);        // ����ƶ�
	void mouseReleaseEvent(QMouseEvent* event);     // ����ͷ�

signals:
	void searchUser_Home_Service(QString& Userid, QString& Searchid);
	void getFriendNotice_Home_Service();
	void addFriend_Home_Service(QString& userid);
	void getFriendship_Home_Service();
	void acceptFriendApply_Home_Service(QString& userid);
	void sendMessage_Home_Service(QString& userid);
	void getMessageLst_Home_Service();
	void getMessageInformation_Home_Service(QString& friendUserid);
	void sendFriendMessage_Home_Service(QString& msg, QString& userid, QString& friendid);

public slots:
	void searchUser_Home_Wgt(QString& Userid, QString& Searchid);
	void getFriendNotice_Home_Wgt();
	void addFriend_Home_Wgt(QString& userid);
	void getFriendship_Home_Wgt();
	void acceptFriendApply_Home_Wgt(QString& userid);
	void sendMessage_Home_Wgt(QString& userid);
	void getMessageLst_Home_Wgt();
	void getMessageInformation_Home_Wgt(QString& friendUserid);
	void sendFriendMessage_Home_Wgt(QString& msg, QString& userid, QString& friendid);

private slots:
	void onTbMinus();       // ��С������
	void onTbClose();       // �رմ���

private:
	Ui::HomeWgt* m_pUi = nullptr;
	MessageWgt* m_pMessageWgt = nullptr;
	FriendWgt* m_pFriendWgt = nullptr;
	ChatAiWgt* m_pChatAiWgt = nullptr;

	/*����¼�*/
	QPoint last;                    // �����϶��ñ���
	bool isPressedWidget = false;   // ����Ƿ�ѹwidget
	
	// ���òۺ���
	void setSlots();

};

#endif
