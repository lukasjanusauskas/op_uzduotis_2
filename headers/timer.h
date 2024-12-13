#ifndef TIMER_H
#define TIMER_H

#include <chrono>

/// @brief Laiko skaičiavimui skirta klasė
class Timer{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> elapsed;

public:
    /// @brief Pradedame laiko skaičiavimą, apskaičiuodami 
    void start_timer();
    /// @brief Apskaičiuojame laiką(veikia tik, jei jau buvome paleidę)
    double get_time();
    /// @brief Per naujo paleisti laiko skaičiuoklį
    void restart_timer();
};

#endif