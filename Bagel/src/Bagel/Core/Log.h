#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Bagel {
	class BAGEL_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetColorLogger() { return s_ColorLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClinetLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_ColorLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define BG_CORE_TRACE(...)	::Bagel::Log::GetColorLogger()->trace(__VA_ARGS__)
#define BG_CORE_INFO(...)	::Bagel::Log::GetColorLogger()->info(__VA_ARGS__)
#define BG_CORE_WARN(...)	::Bagel::Log::GetColorLogger()->warn(__VA_ARGS__)
#define BG_CORE_ERROR(...)	::Bagel::Log::GetColorLogger()->error(__VA_ARGS__)
#define BG_CORE_FATAL(...)	::Bagel::Log::GetColorLogger()->critical(__VA_ARGS__)

#define BG_TRACE(...)		::Bagel::Log::GetClinetLogger()->trace(__VA_ARGS__)
#define BG_INFO(...)		::Bagel::Log::GetClinetLogger()->info(__VA_ARGS__)
#define BG_WARN(...)		::Bagel::Log::GetClinetLogger()->warn(__VA_ARGS__)
#define BG_ERROR(...)		::Bagel::Log::GetClinetLogger()->error(__VA_ARGS__)
#define BG_FATAL(...)		::Bagel::Log::GetClinetLogger()->critical(__VA_ARGS__)