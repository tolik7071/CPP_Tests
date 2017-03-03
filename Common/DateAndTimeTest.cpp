#include "stdafx.h"
#include "DateAndTimeTest.h"
#include <chrono>
#include <ctime>
#include <ratio>
#include <thread>

void DateAndTimeTest::ChronoIntervalTest()
{
	/*
		*_clock
		time_point
		duration
	*/
	std::chrono::seconds oneSecond(1);

	std::cout << "1 second consist of:" << std::endl;
	std::cout << "\t" << std::chrono::milliseconds(oneSecond).count() << " milliseconds" << std::endl;
	std::cout << "\t" << std::chrono::microseconds(oneSecond).count() << " microseconds" << std::endl;
	std::cout << "\t" << std::chrono::nanoseconds(oneSecond).count() << " nanoseconds" << std::endl;

	auto start = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<long long, std::nano> elapsed = end - start;
	std::cout << "Elapsed " << elapsed.count() << " nanoseconds" << std::endl;
}