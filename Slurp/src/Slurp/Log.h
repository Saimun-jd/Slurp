#pragma once
#include<memory>
#include "Core.h"
#include<spdlog/spdlog.h>
#include "spdlog/fmt/ostr.h"

namespace Slurp
{
	class SLURP_API Log
	{

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }

		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return cliantLogger; }

	private:
		static std::shared_ptr<spdlog::logger> cliantLogger;
		static std::shared_ptr<spdlog::logger> coreLogger;
	};
}


//---------------Core Log macros---------------
#define SL_CORE_TRACE(...)		::Slurp::Log::getCoreLogger()->trace(__VA_ARGS__)
#define SL_CORE_WARN(...)		::Slurp::Log::getCoreLogger()->warn(__VA_ARGS__)
#define SL_CORE_INFO(...)		::Slurp::Log::getCoreLogger()->info(__VA_ARGS__)
#define SL_CORE_ERROR(...)		::Slurp::Log::getCoreLogger()->error(__VA_ARGS__)
#define SL_CORE_FATAL(...)		::Slurp::Log::getCoreLogger()->fatal(__VA_ARGS__)
//----------------------------------------


//---------------Cliant Log macros---------------
// Client log macros
#define SL_TRACE(...)	      ::Slurp::Log::getClientLogger()->trace(__VA_ARGS__)
#define SL_INFO(...)	      ::Slurp::Log::getClientLogger()->info(__VA_ARGS__)
#define SL_WARN(...)	      ::Slurp::Log::getClientLogger()->warn(__VA_ARGS__)
#define SL_ERROR(...)	      ::Slurp::Log::getClientLogger()->error(__VA_ARGS__)
#define SL_FATAL(...)	      ::Slurp::Log::getClientLogger()->fatal(__VA_ARGS__)
//----------------------------------------
