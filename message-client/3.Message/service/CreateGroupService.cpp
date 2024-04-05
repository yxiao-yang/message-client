#include "CreateGroupService.h"
#include "pub.const.h"
#include "pub.cache.h"
#include "ConnectServer.h"
#include "user.hpp"
#include <QDebug>

CreateGroupService::CreateGroupService()
{

}

CreateGroupService::~CreateGroupService()
{

}

void CreateGroupService::createGroup(QString& groupName, std::vector<User>& friendSelected)
{
	json js;
	js["msgid"] = CREATE_GROUP_MSG;
	js["GroupName"] = groupName.toStdString();
	std::vector<std::string> arrUser;
	std::string userID;
	if (PubCache::getInstance()->getUserid(userID))
	{
		arrUser.push_back(userID);
	}
    for (int i = 0; i < friendSelected.size(); ++i)
    {
		std::string friendid = friendSelected[i].getId();
		arrUser.push_back(friendid);
    }
    js["Users"] = arrUser;
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send CREATE_GROUP_MSG fail";
	}
	else
	{
		qDebug() << "send CREATE_GROUP_MSG success";
	}
}

void CreateGroupService::createGroupAck(json& js)
{
	emit showCreateGroupAck_Home_Service();
}
