#ifndef _SERVICE_H_
#define _SERVICE_H_

#include "json.hpp"
#include "pub.const.h"
#include "RegService.h"

using json = nlohmann::json;

using MsgHandler = std::function<void(json&)>;

class Service
{
public:
	// 单例接口
	static Service* getInstance();

	// 通过消息ID获取对应方法
	MsgHandler getHandler(enMsgType iMsgId);
private:
	Service();

	// 消息ID和对应的方法
	std::unordered_map<int, MsgHandler> m_mapMsgHandler;

	// 注册业务
	RegService* m_pRegService = nullptr;
};

#endif

