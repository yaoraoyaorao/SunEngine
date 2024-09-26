#pragma once

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace SunEngine {
	class Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_ClientLogger;
	};
}

#define SUN_CORE_ERROR(...)		::SunEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SUN_CORE_WARN(...)		::SunEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SUN_CORE_INFO(...)		::SunEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SUN_CORE_TRACE(...)		::SunEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define SUN_ERROR(...)			::SunEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SUN_WARN(...)			::SunEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SUN_INFO(...)			::SunEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SUN_TRACE(...)			::SunEngine::Log::GetClientLogger()->trace(__VA_ARGS__)