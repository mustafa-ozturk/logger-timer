#include "Timer.h"
#include "Logger.h"

Timer::Timer(const char* message, int line, const char* srcFile)
    : m_line(line), m_srcFile(srcFile), m_message(message)
{
    m_StartTimepoint = std::chrono::high_resolution_clock::now();
}
Timer::~Timer()
{
    Stop();
}

void Timer::Stop()
{
    auto endTimepoint = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

    auto duration = end - start;
    double ms = duration * 0.001;

    Logger::Timer(m_line, m_srcFile, "%s duration: %lf ms", m_message, ms);
}

