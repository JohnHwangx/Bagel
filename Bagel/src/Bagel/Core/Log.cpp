#include "bgpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Bagel {
	std::shared_ptr<spdlog::logger> Log::s_ColorLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_ColorLogger = spdlog::stdout_color_mt("Bagel");
		s_ColorLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}