#pragma once
#include <chrono>
#include <iostream>


#define INVALID -1

class Timer {

public:
	Timer();

public:

	void StartTimer() const;

	void StopTimer() const;

	inline float ElapsedTimeInMili() const { return Timer::m_ElapsedTime; }

	inline float ElapsedTimeInSecound() const { return Timer::m_ElapsedTime / 1000.0f; }

	inline void PrintResults(const char* testName, const bool& checkIfSorted) const
	{
		if (checkIfSorted)
		{
			printf(":\t: sorted in %10.3f ms, %10.3f s", ElapsedTimeInMili(), ElapsedTimeInSecound());
		}
		else
		{
			std::cout << testName << "Not Sorted!!!" << std::endl;
		}
	}

private:
	mutable float m_ElapsedTime;
	mutable bool m_IsTimerStarted;
	mutable std::chrono::time_point<std::chrono::steady_clock> m_Start;
	mutable std::chrono::time_point<std::chrono::steady_clock> m_End;
	mutable std::chrono::duration<float> m_Duration;
};

