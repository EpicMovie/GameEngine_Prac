#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace PEngine
{
	class PEngine_API Log
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

#define PE_CORE_TRACE(...)	::PEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PE_CORE_INFO(...)	::PEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PE_CORE_WARN(...)	::PEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PE_CORE_ERROR(...)	::PEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PE_CORE_FATAL(...)	::PEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define PE_TRACE(...)		::PEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PE_INFO(...)		::PEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define PE_WARN(...)		::PEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PE_ERROR(...)		::PEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define PE_FATAL(...)		::PEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
