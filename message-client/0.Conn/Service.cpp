#include "Service.h"

Service* Service::getInstance()
{
	static Service service;
	return &service;
}

Service::Service()
{
    m_pRegService = new RegService;
    m_pLoginService = new LoginService;
    m_pRegSuccessService = new RegSuccessService;
    m_pHomeService = new HomeService;

    connect(m_pLoginService, &LoginService::showRegWgt_Service, this, &Service::showRegWgt_Service);
    connect(m_pRegService, &RegService::showLoginWgt_Service, this, &Service::showLoginWgt_Service);
    connect(m_pRegService, &RegService::showRegSuccessWgt_Service, this, &Service::showRegSuccessWgt_Service);
    connect(m_pRegSuccessService, &RegSuccessService::showLoginWgt_Service, this, &Service::showLoginWgt_Service);
    connect(m_pLoginService, &LoginService::showHomeWgt_Service, this, &Service::showHomeWgt_Service);

    // ע����Ϣ�Ͷ�ӦHandler�ص�
    m_mapMsgHandler.insert({ REG_MSG_ACK, std::bind(&RegService::reg, m_pRegService, std::placeholders::_1) });
    m_mapMsgHandler.insert({ LOGIN_MSG_ACK, std::bind(&LoginService::login, m_pLoginService, std::placeholders::_1) });
    m_mapMsgHandler.insert({ SEARCH_USER_MSG_ACK, std::bind(&HomeService::search_ack, m_pHomeService, std::placeholders::_1) });
    m_mapMsgHandler.insert({ ADD_FRIEND_MSG_ACK, std::bind(&HomeService::addFriendAns, m_pHomeService, std::placeholders::_1) });
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

void Service::showLoginWgt()
{
    m_pLoginService->showLoginWgt();
}

void Service::showLoginWgt_Service()
{
    m_pLoginService->showLoginWgt();
}

void Service::showRegWgt_Service()
{
    m_pRegService->showRegWgt();
}

void Service::showRegSuccessWgt_Service(std::string& Userid)
{
    m_pRegSuccessService->showRegSuccessWgt(Userid);
}

void Service::showHomeWgt_Service()
{
    m_pHomeService->showHomeWgt();
}
