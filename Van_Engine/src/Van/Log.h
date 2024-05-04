#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Van
{
	class VAN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log macros
#define VAN_CORE_TRACE(...)    ::Van::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VAN_CORE_INFO(...)     ::Van::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VAN_CORE_WARN(...)     ::Van::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VAN_CORE_ERROR(...)    ::Van::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VAN_CORE_FATAL(...)    ::Van::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define VAN_TRACE(...)         ::Van::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VAN_INFO(...)          ::Van::Log::GetClientLogger()->info(__VA_ARGS__)
#define VAN_WARN(...)          ::Van::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VAN_ERROR(...)         ::Van::Log::GetClientLogger()->error(__VA_ARGS__)
#define VAN_FATAL(...)         ::Van::Log::GetClientLogger()->fatal(__VA_ARGS__)