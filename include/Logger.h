#pragma once

#include <cstdio>
#include <map>
#include <ctime>
#include <iostream>
#include "Colors.h"

#define LOG_DEBUG(Message, ...) (Logger::Debug(__LINE__, __FILE__, Message, __VA_ARGS__))
#define LOG_INFO(Message, ...) (Logger::Info(__LINE__, __FILE__, Message, __VA_ARGS__))
#define LOG_ERROR(Message, ...) (Logger::Error(__LINE__, __FILE__, Message, __VA_ARGS__))

class Logger
{
public:
    enum LogPriority
    {
        TimerPriority,
        DebugPriority,
        InfoPriority,
        ErrorPriority,
    };

    static void setPriority(LogPriority priority);

    static void EnableFileOutput();

    static void EnableFileOutput(const char* filePath);

    template<typename... Args>
    static void Timer(int line, const char* srcFile, const char* message, Args... args)
    {
        getInstance().log(
                line,
                srcFile,
                TimerPriority,
                message,
                args...
        );
    }

    template<typename... Args>
    static void Debug(int line, const char* srcFile, const char* message, Args... args)
    {
        getInstance().log(
                line,
                srcFile,
                DebugPriority,
                message,
                args...
        );
    }

    template<typename... Args>
    static void Info(int line, const char* srcFile, const char* message, Args... args)
    {
        getInstance().log(
                line,
                srcFile,
                InfoPriority,
                message,
                args...
        );
    }

    template<typename... Args>
    static void Error(int line, const char* srcFile, const char* message, Args... args)
    {
        getInstance().log(
                line,
                srcFile,
                ErrorPriority,
                message,
                args...
        );
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
private:
    Logger();
    ~Logger();

    static Logger& getInstance();
    const std::map<LogPriority, std::string> m_logTypesTerminal;
    const std::map<LogPriority, const char*> m_logTypesTxt;
    LogPriority m_priority = LogPriority::DebugPriority;
    FILE* m_file = nullptr;
    const char* m_filePath = nullptr;

    void appendFileOutput();

    void freeFile();

    template<typename... T>
    void log(int line, const char* srcFile, LogPriority priority, const char* message, T... args)
    {
        std::time_t currentTime = std::time(0);
        std::tm* timeStamp = std::localtime(&currentTime);
        char buffer[80];
        strftime(buffer, 80, "%D::%r", timeStamp);

        std::string logTypeTerminal = m_logTypesTerminal.at(priority);
        const char* logTypeTxt = m_logTypesTxt.at(priority);

        if (m_priority <= priority)
        {
            printf("%s", logTypeTerminal.c_str());
            printf("%s\t\t", buffer);
            printf(message, args...);
            printf("\n\t\t");
            printf("in %s:%d\n", srcFile, line);
        }

        if (m_file)
        {
            fprintf(m_file, "%s\t", logTypeTxt);
            fprintf(m_file, "%s\n\t\t", buffer);
            fprintf(m_file, message, args...);
            fprintf(m_file, "\n\t\t");
            fprintf(m_file, "in %s:%d\n", srcFile, line);
        }
    };

};

