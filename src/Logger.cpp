#include "Logger.h"

void Logger::setPriority(LogPriority priority)
{
    getInstance().m_priority = priority;
}

void Logger::EnableFileOutput()
{
    Logger& loggerInstance = getInstance();
    loggerInstance.m_filePath = "log.text";
    loggerInstance.appendFileOutput();
}

void Logger::EnableFileOutput(const char* filePath)
{
    Logger& loggerInstance = getInstance();
    loggerInstance.m_filePath = filePath;
    loggerInstance.appendFileOutput();
}

Logger::~Logger()
{
    freeFile();
}

Logger& Logger::getInstance()
{
    static Logger logger;
    return logger;
}


Logger::Logger()
        : m_priority(LogPriority::DebugPriority),
          m_logTypesTerminal({
              {LogPriority::TimerPriority,    TColors::BoldYellow("[TIMER]\t\t")},
              {LogPriority::DebugPriority,    TColors::BoldBlue("[DEBUG]\t\t")},
              {LogPriority::InfoPriority,     TColors::BoldGreen("[INFO]\t\t")},
              {LogPriority::ErrorPriority,    TColors::BoldLightRed("[ERROR]\t\t")},
          }),
          m_logTypesTxt({
              {LogPriority::TimerPriority,    "[TIMER]"},
              {LogPriority::DebugPriority,    "[DEBUG]"},
              {LogPriority::InfoPriority,     "[INFO]"},
              {LogPriority::ErrorPriority,    "[ERROR]"},
          }),
          m_file(nullptr),
          m_filePath(nullptr)
{
}

void Logger::appendFileOutput()
{
    if (m_file != nullptr)
    {
        fclose(m_file);
    }

    m_file = fopen(m_filePath, "a");

    if (m_file == nullptr)
    {
        LOG_ERROR("Logger: Failed to open file at %s", m_filePath);
    }
}

void Logger::freeFile()
{
    fclose(m_file);
    m_file = nullptr;
}