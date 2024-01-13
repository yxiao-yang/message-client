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
	// �����ӿ�
	static Service* getInstance();

	// ͨ����ϢID��ȡ��Ӧ����
	MsgHandler getHandler(enMsgType iMsgId);
private:
	Service();

	// ��ϢID�Ͷ�Ӧ�ķ���
	std::unordered_map<int, MsgHandler> m_mapMsgHandler;

	// ע��ҵ��
	RegService* m_pRegService = nullptr;
};

#endif

