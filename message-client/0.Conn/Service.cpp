#include "Service.h"

Service* Service::getInstance()
{
	static Service service;
	return &service;
}

Service::Service()
{
    m_pRegService = new RegService;
    // ע����Ϣ�Ͷ�ӦHandler�ص�
    m_mapMsgHandler.insert({ REG_MSG_ACK, std::bind(&RegService::reg, m_pRegService, std::placeholders::_1) });
}

MsgHandler Service::getHandler(enMsgType iMsgId)
{
    // iMsgIdû�ж�Ӧ�Ļص�
    auto it = m_mapMsgHandler.find(iMsgId);
    if (it == m_mapMsgHandler.end())
    {
        // ����һ���ղ���Handler
        return [=](json&)
            {
                
            };
    }
    else
    {
        return m_mapMsgHandler[iMsgId];
    }
}
