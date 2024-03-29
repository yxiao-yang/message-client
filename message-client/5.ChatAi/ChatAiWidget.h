#ifndef _CHAT_AI_WIDGET_H_
#define _CHAT_AI_WIDGET_H_

#include "ui_ChatAiWidget.h"
#include "ChatAiWindowWidget.h"
#include "user.hpp"
#include "chatai_message.hpp"
#include <QWidget>
#include <unordered_map>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatAiWgt; };
QT_END_NAMESPACE

class ChatAiWgt : public QWidget
{
	Q_OBJECT
public:
	ChatAiWgt(QWidget* parent = nullptr);
	~ChatAiWgt();

	// 获取左侧列表
	void getChatAiLst();

	void showChatAiLst(std::map<std::string, std::string>& mapContentIdTime);

	void showNewAiChat(std::string& contentid);

	void showChatAiMessage(std::vector<ChatAiMessage*>& arrMessage);

	void showNewChatAiMessage(QString& msg, QString& contentid);

public slots:
	void getChatAiMessageInformation_ChatAi_Wgt(QString& contentid);
	void sendChatAiMessage_ChatAi_Wgt(QString& msg, QString& contentid);

private slots:
	void onAddPb();
	void onChatAiLstItemWgt(QString& contentid);

signals:
	void getChatAiLst_Home_Wgt();
	void startNewChat_Home_Wgt();
	void getChatAiMessageInformation_Home_Wgt(QString& contentid);
	void sendChatAiMessage_Home_Wgt(QString& msg, QString& contentid);

private:
	Ui::ChatAiWgt* m_pUi = nullptr;

	QWidget* m_pEmptyWgt = nullptr;
	ChatAiWindowWgt* m_pChatAiWindowWgt = nullptr;
	std::vector<QListWidgetItem*> m_arrChatAiLstItemWgt;
	std::map<std::string, std::string> m_mapContentIdTime;
	QString m_strCurrentContentId;
	
	void setSlots();
	void switchChatAiSWgt(int idx);
};

#endif