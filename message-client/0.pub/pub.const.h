#ifndef _PUB_CONST_H
#define _PUB_CONST_H

enum enMsgType
{
	LOGIN_MSG = 0,                        // 登录消息
	LOGIN_MSG_ACK,                        // 登录响应消息
	REG_MSG,                              // 注册消息
	REG_MSG_ACK,                          // 注册响应消息
	ADD_FRIEND_MSG,                       // 添加好友
	ADD_FRIEND_MSG_ACK,                   // 添加好友响应消息
	SEARCH_USER_MSG,                      // 搜索用户
	SEARCH_USER_MSG_ACK,                  // 搜索用户响应
	FRIEND_NOTICE_MSG,                    // 好友通知消息
	FRIEND_NOTICE_MSG_ACK,                // 好友通知消息响应
	ACCEPT_APPLY_MSG,                     // 同意好友申请
	ACCEPT_APPLY_MSG_ACK,                 // 同意好友申请响应
	SEND_CHAT_AI_MSG,                     // Ai对话
	SEND_CHAT_AI_MSG_ACK,                 // Ai对话响应
	GET_CHAT_AI_LST_MSG,                  // 获取AI对话消息列表
	GET_CHAT_AI_LST_MSG_ACK,              // 获取AI对话消息列表响应
	START_NEW_AI_CHAT_MSG,                // 开启AI对话新聊天
	START_NEW_AI_CHAT_MSG_ACK,            // 开启AI对话新聊天响应
	GET_CHAT_AI_MESSAGE_INFORMATION_MSG,  // 获取AI对话历史聊天消息
	GET_CHAT_AI_MESSAGE_INFORMATION_MSG_ACK,  // 获取AI对话历史聊天消息响应
	GET_FRIENDSHIP_MSG,                       // 获取联系人消息
	GET_FRIENDSHIP_MSG_ACK,                   // 获取联系人消息响应
	SEND_MESSAGE_MSG,                         // 发送聊天请求消息
	SEND_MESSAGE_MSG_ACK,                     // 发送聊天请求消息
	GET_MESSAGELST_MSG,                       // 获取消息列表消息
	GET_MESSAGELST_MSG_ACK,                   // 获取聊天列表消息响应
	GET_CHAT_MESSAGE_MSG,                     // 好友聊天消息
	GET_CHAT_MESSAGE_MSG_ACK,                 // 好友聊天消息响应
	SEND_FRIEND_MESSAGE_MSG,                  // 给好友发送聊天消息
	SEND_FRIEND_MESSAGE_MSG_ACK,              // 给好友发送聊天消息响应
	GET_FRIEND_MESSAGE_ACK,                   // 获取好友消息响应
	TRANSLATE_MESSAGE_MSG,                    // 翻译消息
	TRANSLATE_MESSAGE_MSG_ACK,                // 翻译消息响应
	BEAUTIFY_MESSAGE_MSG,                     // 美化消息
	BEAUTIFY_MESSAGE_MSG_ACK,                 // 美化消息响应
	CREATE_GROUP_MSG,                         // 创建群聊消息
	CREATE_GROUP_MSG_ACK,                     // 创建群聊响应
	GET_GROUPLST_MSG,                         // 获取群组列表
	GET_GROUPLST_MSG_ACK,                     // 获取群组列表响应
	SEND_GROUP_MESSAGE_MSG,                   // 向群发送消息
	SEND_GROUP_MESSAGE_MSG_ACK                // 向群发送消息响应
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
	CHATAI_WIDGET,
	GROUP_WIDGET
};

enum enMessageStackedWidgetId
{
	MESSAGE_EMPTY_WIDGET = 0,
	ADDFRIEND_WIDGET,
	MESSAGE_WINDOW_WIDGET,
	CREATE_GROUP_WIDGET
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

enum enGroupStackedWidgetId
{
	GROUP_EMPTY_WIDGET = 0,
	GROUP_INFORMATION_WIDGET
};

#endif
