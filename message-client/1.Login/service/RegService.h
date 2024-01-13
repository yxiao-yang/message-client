#ifndef _REG_SERVICE_H_
#define _REG_SERVICE_H_

#include "RegSuccessWidget.h"
#include "json.hpp"

using json = nlohmann::json;

class RegService
{
public:
	RegService();

	// зЂВс
	void reg(json& js);

private:
	RegSuccessWidget* m_pRegSuccessWgt = nullptr;
};


#endif // ! _REG_SERVICE_H_
