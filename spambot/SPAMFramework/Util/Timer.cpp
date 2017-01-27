#include "Timer.h"

Timer::Timer(){
	ResetAndStart();
}

void Timer::ResetAndStart() {
	m_last_time = boost::chrono::high_resolution_clock::now();
}

double Timer::GetElapsedTime() {
	boost::chrono::high_resolution_clock::time_point current = 
			boost::chrono::high_resolution_clock::now();

	int ns = boost::chrono::duration_cast<boost::chrono::nanoseconds>(current - m_last_time).count();
	double secs = ns * 1e-9;
	return secs;
}


