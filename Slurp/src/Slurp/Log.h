#pragma once
#include<memory>
#include "Core.h"
#include<spdlog/spdlog.h>

namespace Slurp
{
	class SLURP_API Log
	{

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }

		inline static std::shared_ptr<spdlog::logger>& getCliantLogger() { return cliantLogger; }

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
#define SL_CLIANT_TRACE(...)	::Slurp::Log::getCliantLogger()->trace(__VA_ARGS__)
#define SL_CLIANT_WARN(...)		::Slurp::Log::getCliantLogger()->warn(__VA_ARGS__)
#define SL_CLIANT_INFO(...)		::Slurp::Log::getCliantLogger()->info(__VA_ARGS__)
#define SL_CLIANT_ERROR(...)	::Slurp::Log::getCliantLogger()->error(__VA_ARGS__)
#define SL_CLIANT_FATAL(...)	::Slurp::Log::getCliantLogger()->fatal(__VA_ARGS__)
//----------------------------------------
