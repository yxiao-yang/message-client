#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <string>

// Message表的ORM类 对象关系映射 避免原生sql 而是操作对象
class Message
{
public:
	Message()
		: m_strMessageId(""),
		m_strSenderId(""),
		m_strReceiverId(""),
		m_strContent(""),
		m_strSendTime(""),
		m_bVisibleStatus(false)
	{
	}
	Message(std::string messageid, std::string senderid, std::string receiverid,
		std::string content, std::string sendtime, bool status)
		: m_strMessageId(messageid),
		m_strSenderId(senderid),
		m_strReceiverId(receiverid),
		m_strContent(content),
		m_strSendTime(sendtime),
		m_bVisibleStatus(status)
	{
	}

	void setMessageId(std::string id) { this->m_strMessageId = id; }
	void setSenderId(std::string id) { this->m_strSenderId = id; }
	void setReceiverId(std::string id) { this->m_strReceiverId = id; }
	void setContent(std::string content) { this->m_strContent = content; }
	void setSendTime(std::string time) { this->m_strSendTime = time; }
	void setState(bool state) { this->m_bVisibleStatus = state; }

	std::string getMessageId() { return this->m_strMessageId; }
	std::string getSenderId() { return this->m_strSenderId; }
	std::string getReceiverId() { return this->m_strReceiverId; }
	std::string getContent() { return this->m_strContent; }
	std::string getSendTime() { return this->m_strSendTime; }
	bool getState() { return this->m_bVisibleStatus; }

protected:
	std::string m_strMessageId;
	std::string m_strSenderId;
	std::string m_strReceiverId;
	std::string m_strContent;
	std::string m_strSendTime;
	bool m_bVisibleStatus;
};

#endif