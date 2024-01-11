#ifndef _PUB_CONST_H
#define _PUB_CONST_H

enum enMsgType
{
	LOGIN_MSG = 0,  // ��¼��Ϣ
	LOGIN_MSG_ACK,  // ��¼��Ӧ��Ϣ
	REG_MSG,        // ע����Ϣ
	REG_MSG_ACK     // ע����Ӧ��Ϣ
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

#endif
