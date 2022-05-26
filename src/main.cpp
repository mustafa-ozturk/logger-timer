#include <iostream>
#include "Logger.h"
#include "Timer.h"


int main()
{
    Logger::EnableFileOutput();
    Logger::setPriority(Logger::TimerPriority);

    {
        Timer timer("for loop", __LINE__, __FILE__);
        for (int i = 0; i < 100000; i++)
            i += 2;
    }

    LOG_DEBUG("Test Message", NULL);
    LOG_INFO("Test Message", NULL);
    LOG_ERROR("Test Message", NULL);

    return 0;
}
