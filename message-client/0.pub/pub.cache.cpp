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
	// ��ȡ��ǰʱ���
	auto now = std::chrono::system_clock::now();

	// ��ʱ���ת��Ϊʱ��ṹ��
	std::time_t time = std::chrono::system_clock::to_time_t(now);
	std::tm localTime = *std::localtime(&time);

	// ʹ��put_time���и�ʽ��
	std::ostringstream oss;
	oss << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");

	return oss.str();
}
