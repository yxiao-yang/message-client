#ifndef _CHATAI_MESSAGE_H_
#define _CHATAI_MESSAGE_H_

#include <string>

// Message���ORM�� �����ϵӳ�� ����ԭ��sql ���ǲ�������
class ChatAiMessage
{
public:
    ChatAiMessage() : m_strMessage(""), m_bUser(false) {}

    ChatAiMessage(std::string message, std::string time, bool isUser)
        : m_strMessage(""), m_bUser(false)
    {
    }

    void setMessage(std::string message) { this->m_strMessage = message; }
    void setType(bool type) { this->m_bUser = type; }

    std::string getMessage() { return this->m_strMessage; }
    bool getType() { return this->m_bUser; }

protected:
    bool m_bUser;
    std::string m_strMessage;
};

#endif