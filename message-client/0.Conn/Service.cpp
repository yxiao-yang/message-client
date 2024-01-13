#include "Service.h"

Service* Service::getInstance()
{
	static Service service;
	return &service;
}

Service::Service()
{
    m_pRegService = new RegService;
    // 注册消息和对应Handler回调
    m_mapMsgHandler.insert({ REG_MSG_ACK, std::bind(&RegService::reg, m_pRegService, std::placeholders::_1) });
}

MsgHandler Service::getHandler(enMsgType iMsgId)
{
    // iMsgId没有对应的回调
    auto it = m_mapMsgHandler.find(iMsgId);
    if (it == m_mapMsgHandler.end())
    {
        // 返回一个空操作Handler
        return [=](json&)
            {
                
            };
    }
    else
    {
        return m_mapMsgHandler[iMsgId];
    }
}
