#pragma once
#include <string>
#include <iostream>

class TColors
{
public:
    static std::string BoldRed(const std::string& s)
    {
        return "\033[" + std::to_string(BOLD) +
                ";" + std::to_string(m_Code::FG_RED) +
                "m" + s + "\033[0m";
    }

    static std::string BoldLightRed(const std::string& s)
    {
        return "\033[" + std::to_string(BOLD) +
               ";" + std::to_string(m_Code::FG_LIGHTRED) +
               "m" + s + "\033[0m";
    }

    static std::string BoldGreen(const std::string& s)
    {
        return "\033[" + std::to_string(BOLD) +
               ";" + std::to_string(m_Code::FG_GREEN) +
               "m" + s + "\033[0m";
    }

    static std::string BoldYellow(const std::string& s)
    {
        return "\033[" + std::to_string(BOLD) +
               ";" + std::to_string(m_Code::FG_YELLOW) +
               "m" + s + "\033[0m";
    }

    static std::string BoldBlue(const std::string& s)
    {
        return "\033[" + std::to_string(BOLD) +
               ";" + std::to_string(m_Code::FG_BLUE) +
               "m" + s + "\033[0m";
    }

    static std::string BoldWhite(const std::string& s)
    {
        return "\033[" + std::to_string(BOLD) +
               ";" + std::to_string(m_Code::FG_WHITE) +
               "m" + s + "\033[0m";
    }

    TColors() = delete;
    TColors(const TColors&) = delete;
    TColors& operator=(const TColors&) = delete;
private:
    enum m_Code {
        BOLD        = 1,
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_YELLOW   = 33,
        FG_BLUE     = 34,
        FG_MAGENTA  = 35,
        FG_CYAN     = 36,
        FG_WHITE    = 37,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49,
        FG_LIGHTRED = 91
    };
};

/* https://misc.flogisoft.com/bash/tip_colors_and_formatting */
