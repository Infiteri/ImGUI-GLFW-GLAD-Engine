#include "Logger.h"
#include "iostream"
#include "windows.h"

namespace Core
{

    Logger::Logger()
    {
    }
    Logger::~Logger()
    {
    }

    void Logger::Init()
    {
        SetConsoleTitleA("Console");
    }

    void Logger::Log(Core::LogLevel level, const char *message, ...)
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

        // 15 = INFO
        // 14 = WARN
        // 4 = ERROR
        // 832 = FATAL

        const char *levels[4] = {"INFO", "WARN", "ERROR", "FATAL"};

        switch (level)
        {
        case LogLevel::LOG_INFO:
            SetConsoleTextAttribute(h, 15);
            break;

        case LogLevel::LOG_WARN:
            SetConsoleTextAttribute(h, 14);
            break;

        case LogLevel::LOG_ERROR:
            SetConsoleTextAttribute(h, 4);
            break;

        case LogLevel::LOG_FATAL:
            SetConsoleTextAttribute(h, 832);
            break;
        }

        char out_message[32000];
        memset(out_message, 0, sizeof(out_message));
        __builtin_va_list arg_ptr;
        va_start(arg_ptr, message);
        vsnprintf(out_message, 32000, message, arg_ptr);
        va_end(arg_ptr);

        printf("[LOG %s]: %s \n", levels[level], out_message);
    }

}
