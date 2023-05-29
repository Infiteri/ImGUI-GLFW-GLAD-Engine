
#include "Core.h"
#include "windows.h"

namespace Core
{
    enum LogLevel
    {
        LOG_INFO,
        LOG_WARN,
        LOG_ERROR,
        LOG_FATAL,
    };

    class CORE_API Logger
    {
    private:
    public:
        Logger();
        ~Logger();

        static void Init();

        static void Log(Core::LogLevel level, const char *message, ...);
    };
}

// INFO: Macros
#define CE_INFO(message, ...) Core::Logger::Log(Core::LogLevel::LOG_INFO, message, ##__VA_ARGS__)
#define CE_WARN(message, ...) Core::Logger::Log(Core::LogLevel::LOG_WARN, message, ##__VA_ARGS__)
#define CE_ERROR(message, ...) Core::Logger::Log(Core::LogLevel::LOG_ERROR, message, ##__VA_ARGS__)
#define CE_FATAL(message, ...) Core::Logger::Log(Core::LogLevel::LOG_FATAL, message, ##__VA_ARGS__)
