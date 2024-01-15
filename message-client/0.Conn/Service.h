#ifndef _SERVICE_H_
#define _SERVICE_H_

#include "json.hpp"
#include "pub.const.h"
#include "RegService.h"
#include "LoginService.h"
#include "RegSuccessService.h"

using json = nlohmann::json;

using MsgHandler = std::function<void(json&)>;

class Service : public QObject
{
	Q_OBJECT
public:
	// �����ӿ�
	static Service* getInstance();

	// ͨ����ϢID��ȡ��Ӧ����
	MsgHandler getHandler(enMsgType iMsgId);

	void showLoginWgt();

public slots:
	void showRegWgt_Service();
	void showLoginWgt_Service();
	void showRegSuccessWgt_Service(std::string& Userid);

private:
	Service();

	// ��ϢID�Ͷ�Ӧ�ķ���
	std::unordered_map<int, MsgHandler> m_mapMsgHandler;

	RegService* m_pRegService = nullptr;
	LoginService* m_pLoginService = nullptr;
	RegSuccessService* m_pRegSuccessService = nullptr;
};

#endif

