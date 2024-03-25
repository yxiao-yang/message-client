#ifndef _PUB_CACHE_H_
#define _PUB_CACHE_H_

#include "user.hpp"
#include <string>
#include <vector>

class PubCache
{
public:
	// 静态接口
	static PubCache* getInstance();

	// 用户赋值
	bool setUser(std::string Userid, std::string Username, std::string Userphone, std::string Usertime);

	// 获取用户
	User* getUser();

	// 获取用户id
	bool getUserid(std::string& userid);

	std::string getCurrentDateTimeMySQLFormat();

private:
	static PubCache* s_pubCache;

	User* m_pMainUser = nullptr;

	PubCache();
	~PubCache();
};

#endif
