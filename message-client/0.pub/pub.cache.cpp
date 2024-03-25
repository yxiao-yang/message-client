#include "pub.cache.h"
#include "user.hpp"

#include <mutex>
#include <iomanip>
#include <iosfwd>
#include <sstream>

PubCache* PubCache::s_pubCache = new PubCache;

PubCache* PubCache::getInstance() { return s_pubCache; }

PubCache::PubCache() {}
PubCache::~PubCache() {}

bool PubCache::setUser(std::string Userid, std::string Username, std::string Userphone, std::string Usertime)
{
	m_pMainUser = new User;
	m_pMainUser->setId(Userid);
	m_pMainUser->setName(Username);
	m_pMainUser->setPhone(Userphone);
	m_pMainUser->setTime(Usertime);

	return true;
}

User* PubCache::getUser()
{
	return m_pMainUser;
}

bool PubCache::getUserid(std::string& userid)
{
	userid = m_pMainUser->getId();
	return true;
}

std::string PubCache::getCurrentDateTimeMySQLFormat()
{
	// 获取当前时间点
	auto now = std::chrono::system_clock::now();

	// 将时间点转换为时间结构体
	std::time_t time = std::chrono::system_clock::to_time_t(now);
	std::tm localTime = *std::localtime(&time);

	// 使用put_time进行格式化
	std::ostringstream oss;
	oss << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");

	return oss.str();
}
