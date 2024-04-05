#ifndef _GROUP_SERVICE_H_
#define _GROUP_SERVICE_H_

#include "json.hpp"
#include "group.hpp"
#include <QWidget>

using json = nlohmann::json;

class GroupService : public QObject
{
	Q_OBJECT
public:
	GroupService();
	~GroupService();

	void getGroupLst();
	void getGroupLstAck(json& js);

	void sendGroupMessage(QString& groupid);

signals:
	void showGroupLst_Home_Service(std::vector<Group>& arrGroup);
};
#endif
