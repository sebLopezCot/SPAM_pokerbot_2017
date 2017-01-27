#ifndef TIMER_H
#define TIMER_H 

#include <chrono>

class Timer
{
public:
	Timer();

	void ResetAndStart();
	double GetElapsedTime();

private:
	boost::chrono::high_resolution_clock::time_point m_last_time;
};

#endif
