#ifndef _MESSAGE_SERVICE_H_
#define _MESSAGE_SERVICE_H_

#include "MessageWidget.h"
#include "json.hpp"

using json = nlohmann::json;

class MessageService : public QObject
{
	Q_OBJECT
public:
	MessageService();
	~MessageService();
};
#endif
