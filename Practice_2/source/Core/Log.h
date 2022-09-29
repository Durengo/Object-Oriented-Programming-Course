#pragma once

#include "Core/_CORE.h"
#include "spdlog/spdlog.h"

namespace CLI
{
    class Log
    {
    public:
        static void Init();

        inline static REF<spdlog::logger> &GetClientLogger() { return ClientLogger; }

    private:
        static REF<spdlog::logger> ClientLogger;
    };
}

// CLIENT SIDE LOGS
#define CLI_ERROR(...) ::CLI::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLI_WARN(...) ::CLI::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLI_INFO(...) ::CLI::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLI_TRACE(...) ::CLI::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CLI_FATAL(...) ::CLI::Log::GetClientLogger()->fatal(__VA_ARGS__)