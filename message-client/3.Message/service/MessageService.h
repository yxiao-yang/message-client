#ifndef _MESSAGE_SERVICE_H_
#define _MESSAGE_SERVICE_H_

#include "MessageWidget.h"
#include "json.hpp"
#include "group.hpp"

using json = nlohmann::json;

class MessageService : public QObject
{
	Q_OBJECT
public:
	MessageService();
	~MessageService();

	void getMessageLst();
	void getMessageLstAck(json& js);

signals:
	void showMessageLst_Home_Service(std::map<std::string, User>& mapTimeUser, std::map<std::string, Group>& mapTimeGroup);
};
#endif
