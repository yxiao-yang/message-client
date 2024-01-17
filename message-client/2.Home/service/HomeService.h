#ifndef _HOME_SERVICE_H_
#define _HOME_SERVICE_H_

#include "HomeWidget.h"
#include "json.hpp"

using json = nlohmann::json;

class HomeService : public QObject
{
	Q_OBJECT
public:
	HomeService();

	void showHomeWgt();

private:
	HomeWidget* m_pHomeWgt = nullptr;
};

#endif
