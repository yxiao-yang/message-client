#ifndef _PUB_CONST_H
#define _PUB_CONST_H

enum enMsgType
{
	LOGIN_MSG = 0,       // ��¼��Ϣ
	LOGIN_MSG_ACK,       // ��¼��Ӧ��Ϣ
	REG_MSG,             // ע����Ϣ
	REG_MSG_ACK,         // ע����Ӧ��Ϣ
	ONE_CHAT_MSG,        // ������Ϣ
	ADD_FRIEND_MSG,      // ���Ӻ���
	SEARCH_USER_MSG,     // �����û�
	SEARCH_USER_MSG_ACK  // �����û���Ӧ
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

enum enHomeStackedWidgetId
{
	MESSAGE_WIDGET = 0,
	FRIEND_WIDGET,
	CHATAI_WIDGET
};

enum enMessageStackedWidgetId
{
	MESSAGE_EMPTY_WIDGET = 0,
	ADDFRIEND_WIDGET
};

enum enFriendStackedWidgetId
{
	FRIEND_EMPTY_WIDGET = 0,
	FRIENDNOTICE_WIDGET
};

#endif
