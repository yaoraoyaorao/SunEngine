#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
namespace SunEngine {
	class SUN_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClineLogger() { return m_CoreLogger; }
	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_ClineLogger;
	};
}

#define SUN_CORE_ERROR(...)		::SunEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SUN_CORE_WARN(...)		::SunEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SUN_CORE_INFO(...)		::SunEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SUN_CORE_TRACE(...)		::SunEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define SUN_ERROR(...)			::SunEngine::Log::GetClineLogger()->error(__VA_ARGS__)
#define SUN_WARN(...)			::SunEngine::Log::GetClineLogger()->warn(__VA_ARGS__)
#define SUN_INFO(...)			::SunEngine::Log::GetClineLogger()->info(__VA_ARGS__)
#define SUN_TRACE(...)			::SunEngine::Log::GetClineLogger()->trace(__VA_ARGS__)

