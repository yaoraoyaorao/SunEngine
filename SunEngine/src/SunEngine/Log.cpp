#include "sunpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
namespace SunEngine {
	std::shared_ptr<spdlog::logger> Log::m_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::m_ClineLogger;

	void Log::Init() {
		
		spdlog::set_pattern("%^[%T] %n: %v%$");
		
		m_CoreLogger = spdlog::stdout_color_mt("SUN");
		m_CoreLogger->set_level(spdlog::level::trace);

		m_ClineLogger = spdlog::stdout_color_mt("APP");
		m_ClineLogger->set_level(spdlog::level::trace);
	} 
	   

}