#ifndef _PUB_CONST_H
#define _PUB_CONST_H

enum enMsgType
{
	LOGIN_MSG = 0,          // 登录消息
	LOGIN_MSG_ACK,          // 登录响应消息
	REG_MSG,                // 注册消息
	REG_MSG_ACK,            // 注册响应消息
	ONE_CHAT_MSG,           // 聊天消息
	ADD_FRIEND_MSG,         // 添加好友
	ADD_FRIEND_MSG_ACK,     // 添加好友响应消息
	SEARCH_USER_MSG,        // 搜索用户
	SEARCH_USER_MSG_ACK,    // 搜索用户响应
	FRIEND_NOTICE_MSG,      // 好友通知消息
	FRIEND_NOTICE_MSG_ACK,  // 好友通知消息响应
	ACCEPT_APPLY_MSG,		// 同意好友申请
	ACCEPT_APPLY_MSG_ACK,	// 同意好友申请响应
	CHAT_AI_MSG,            // Ai对话
	GET_FRIENDSHIP_MSG,		// 获取联系人消息
	GET_FRIENDSHIP_MSG_ACK,	// 获取联系人消息响应
	SEND_MESSAGE_MSG,		// 发送聊天请求消息
	SEND_MESSAGE_MSG_ACK,	// 发送聊天请求消息
	GET_MESSAGELST_MSG,		// 获取消息列表消息
	GET_MESSAGELST_MSG_ACK	// 获取聊天列表消息响应
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

enum enSearchType
{
	SEARCH_SUCCESS = 0, // 搜索成功
	SEARCH_ERR_NONE,    // 搜索失败，无结果
	SEARCH_ERR_WRONG    // 搜索失败
};

enum enApplyType
{
	APPLY_SUCCESS = 0,  // 申请好友成功
	APPLY_ERR_REPEAT,   // 申请好友失败，重复申请
	APPLY_ERR_WRONG     // 申请好友失败
};

enum enAcceptApplyType
{
	ACCEPT_APPLY_SUCCESS = 0, // 接受好友申请成功
	ACCEPT_APPLY_WRONG        // 接受好友申请失败
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
	FRIEND_NOTICE_WIDGET,
	FRIEND_INFORMATION_WIDGET
};

#endif
