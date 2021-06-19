#include "Logger.h"
#include <ctime>

void Mithril::Logger::Log(const char* log)
{
	std::cout << log << std::endl;
}

void Mithril::Logger::Log(const std::string& log)
{
	Log(log.c_str());
}

void Mithril::Logger::StampedLog(const char* log)
{	
	char* stampBuffer = (char*) alloca(30 * sizeof(char));

	std::time_t time = std::time(nullptr);
	std::tm timeData;
	
	localtime_s(&timeData, &time);

	std::strftime(stampBuffer, 30, "[%H:%M:%S] ", &timeData);

	std::cout << stampBuffer << log << std::endl;
}

void Mithril::Logger::StampedLog(const std::string& log)
{
	StampedLog(log.c_str());
}