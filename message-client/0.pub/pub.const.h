#ifndef _PUB_CONST_H
#define _PUB_CONST_H

enum enMsgType
{
	LOGIN_MSG = 0,                        // ��¼��Ϣ
	LOGIN_MSG_ACK,                        // ��¼��Ӧ��Ϣ
	REG_MSG,                              // ע����Ϣ
	REG_MSG_ACK,                          // ע����Ӧ��Ϣ
	ADD_FRIEND_MSG,                       // ��Ӻ���
	ADD_FRIEND_MSG_ACK,                   // ��Ӻ�����Ӧ��Ϣ
	SEARCH_USER_MSG,                      // �����û�
	SEARCH_USER_MSG_ACK,                  // �����û���Ӧ
	FRIEND_NOTICE_MSG,                    // ����֪ͨ��Ϣ
	FRIEND_NOTICE_MSG_ACK,                // ����֪ͨ��Ϣ��Ӧ
	ACCEPT_APPLY_MSG,                     // ͬ���������
	ACCEPT_APPLY_MSG_ACK,                 // ͬ�����������Ӧ
	SEND_CHAT_AI_MSG,                     // Ai�Ի�
	SEND_CHAT_AI_MSG_ACK,                 // Ai�Ի���Ӧ
	GET_CHAT_AI_LST_MSG,                  // ��ȡAI�Ի���Ϣ�б�
	GET_CHAT_AI_LST_MSG_ACK,              // ��ȡAI�Ի���Ϣ�б���Ӧ
	START_NEW_AI_CHAT_MSG,                // ����AI�Ի�������
	START_NEW_AI_CHAT_MSG_ACK,            // ����AI�Ի���������Ӧ
	GET_CHAT_AI_MESSAGE_INFORMATION_MSG,  // ��ȡAI�Ի���ʷ������Ϣ
	GET_CHAT_AI_MESSAGE_INFORMATION_MSG_ACK,  // ��ȡAI�Ի���ʷ������Ϣ��Ӧ
	GET_FRIENDSHIP_MSG,                       // ��ȡ��ϵ����Ϣ
	GET_FRIENDSHIP_MSG_ACK,                   // ��ȡ��ϵ����Ϣ��Ӧ
	SEND_MESSAGE_MSG,                         // ��������������Ϣ
	SEND_MESSAGE_MSG_ACK,                     // ��������������Ϣ
	GET_MESSAGELST_MSG,                       // ��ȡ��Ϣ�б���Ϣ
	GET_MESSAGELST_MSG_ACK,                   // ��ȡ�����б���Ϣ��Ӧ
	GET_CHAT_MESSAGE_MSG,                     // ����������Ϣ
	GET_CHAT_MESSAGE_MSG_ACK,                 // ����������Ϣ��Ӧ
	SEND_FRIEND_MESSAGE_MSG,                  // �����ѷ���������Ϣ
	SEND_FRIEND_MESSAGE_MSG_ACK,              // �����ѷ���������Ϣ��Ӧ
	GET_FRIEND_MESSAGE_ACK                    // ��ȡ������Ϣ��Ӧ
};

enum enRegType
{
	REG_SUCCESS = 0,  // ע��ɹ�
	REG_ERROR         // ע��ʧ�ܣ�д�����ݿ�ʧ��
};

enum enLoginType
{
	LOGIN_SUCCESS = 0,  // ��¼�ɹ�
	LOGIN_ERR_REPEAT,   // ��¼ʧ�ܣ��Ѿ�����
	LOGIN_ERR_WRONG     // ��¼ʧ�ܣ��û������������
};

enum enSearchType
{
	SEARCH_SUCCESS = 0, // �����ɹ�
	SEARCH_ERR_NONE,    // ����ʧ�ܣ��޽��
	SEARCH_ERR_WRONG    // ����ʧ��
};

enum enApplyType
{
	APPLY_SUCCESS = 0,  // ������ѳɹ�
	APPLY_ERR_REPEAT,   // �������ʧ�ܣ��ظ�����
	APPLY_ERR_WRONG     // �������ʧ��
};

enum enAcceptApplyType
{
	ACCEPT_APPLY_SUCCESS = 0, // ���ܺ�������ɹ�
	ACCEPT_APPLY_WRONG        // ���ܺ�������ʧ��
};

enum enHomeStackedWidgetId
{
	MESSAGE_WIDGET = 0,
	FRIEND_WIDGET,
	CHATAI_WIDGET
};

enum enMessageStackedWidgetId
{
	MESSAGE_EMPTY_WIDGET = 0,
	ADDFRIEND_WIDGET,
	MESSAGE_WINDOW_WIDGET
};

enum enFriendStackedWidgetId
{
	FRIEND_EMPTY_WIDGET = 0,
	FRIEND_NOTICE_WIDGET,
	FRIEND_INFORMATION_WIDGET
};

enum enChatAiStackedWidgetId
{
	CHATAI_EMPTY_WIDGET = 0,
	CHATAI_WINDOW_WIDGET
};

#endif
