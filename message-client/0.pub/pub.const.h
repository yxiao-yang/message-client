#ifndef _PUB_CONST_H
#define _PUB_CONST_H

enum enMsgType
{
	LOGIN_MSG = 0,  // 登录消息
	LOGIN_MSG_ACK,  // 登录响应消息
	REG_MSG,        // 注册消息
	REG_MSG_ACK     // 注册响应消息
};

enum enRegType
{
	REG_SUCCESS = 0,  // 注册成功
	REG_ERROR         // 注册失败，写入数据库失败
};

enum enLoginType
{
	LOGIN_SUCCESS = 0,  // 登录成功
	LOGIN_ERR_REPEAT,   // 登录失败，已经在线
	LOGIN_ERR_WRONG     // 登录失败，用户名或密码错误
};

#endif
