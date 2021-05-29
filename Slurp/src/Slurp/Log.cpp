#include "pch.h"
#include<spdlog/sinks/stdout_color_sinks.h>

namespace Slurp {

	std::shared_ptr<spdlog::logger> Log::cliantLogger;
	std::shared_ptr<spdlog::logger> Log::coreLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		
		coreLogger = spdlog::stdout_color_mt("Slurp");
		coreLogger->set_level(spdlog::level::trace);

		cliantLogger = spdlog::stdout_color_mt("APP");
		cliantLogger->set_level(spdlog::level::trace);
	}
}
