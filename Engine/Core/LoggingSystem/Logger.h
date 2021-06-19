#pragma once
#include <iostream>
#include <chrono>

namespace Mithril
{
	class Logger
	{
		using system_clock = std::chrono::system_clock;
	public:
		Logger() = default;
		static void Log(const std::string& log);
		static void Log(const char* log);
		static void StampedLog(const std::string& log);
		static void StampedLog(const char* log);
	private:
	};
}