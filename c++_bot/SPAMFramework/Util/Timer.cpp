
// #include "Timer.h"

// Timer::Timer() {
// 	Restart();
// }

// void Timer::Restart()
// {
//     _start_time = boost::chrono::high_resolution_clock::now();
// }

// double Timer::GetElapsedTime()
// {
//     boost::chrono::nanoseconds nano_s = boost::chrono::duration_cast<boost::chrono::nanoseconds>(boost::chrono::high_resolution_clock::now() - _start_time);
//     double d = static_cast<boost::uint64_t>(nano_s.count()) * 1e-9;
//     return d;
// }
