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
	// 单例接口
	static Service* getInstance();

	// 通过消息ID获取对应方法
	MsgHandler getHandler(enMsgType iMsgId);

	void showLoginWgt();

public slots:
	void showRegWgt_Service();
	void showLoginWgt_Service();
	void showRegSuccessWgt_Service(std::string& Userid);

private:
	Service();

	// 消息ID和对应的方法
	std::unordered_map<int, MsgHandler> m_mapMsgHandler;

	RegService* m_pRegService = nullptr;
	LoginService* m_pLoginService = nullptr;
	RegSuccessService* m_pRegSuccessService = nullptr;
};

#endif

