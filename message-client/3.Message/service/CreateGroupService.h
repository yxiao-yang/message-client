#ifndef _CREATE_GROUP_SERVICE_H_
#define _CREATE_GROUP_SERVICE_H_

#include "json.hpp"
#include "user.hpp"
#include <QWidget>

using json = nlohmann::json;

class CreateGroupService : public QObject
{
	Q_OBJECT
public:
	CreateGroupService();
	~CreateGroupService();

	void createGroup(QString& groupName, std::vector<User>& friendSelected);
	void createGroupAck(json& js);

signals:
	void showCreateGroupAck_Home_Service();
};
#endif
