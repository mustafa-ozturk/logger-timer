#pragma once

#include <chrono>

class Timer
{
public:
    Timer(const char* message, int line, const char* srcFile);
    ~Timer();
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
    int m_line;
    const char* m_srcFile;
    const char* m_message;

    void Stop();
};