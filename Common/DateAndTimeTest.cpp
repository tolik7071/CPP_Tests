#if defined(_MSC_VER)
#include "stdafx.h"
#endif // _MSC_VER
#include "DateAndTimeTest.h"
#include <chrono>
#include <ctime>
#include <ratio>
#include <thread>
#include <ctime>
#include "common.h"

void DateAndTimeTest::ChronoIntervalTest()
{
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

void DateAndTimeTest::DateTimeTests()
{
	typedef std::chrono::high_resolution_clock TClock;

	TClock::time_point start = TClock::now();

	for (int i = 0; i < 5; i++)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	TClock::time_point end = TClock::now();

	TClock::duration elapsed = end - start;
	std::cout << "Elapsed " << elapsed.count() << " nanoseconds" << std::endl;
	std::cout << "Elapsed " << std::chrono::duration_cast<std::chrono::seconds>(elapsed).count() << " seconds" << std::endl;

	typedef std::chrono::system_clock TSystemClock;

	std::time_t now = TSystemClock::to_time_t(TSystemClock::now());
	
#if defined(_MSC_VER)
    tm tm;
    localtime_s(&tm, &now);

	char buffer[1024] = { 0 };
	if (0 == asctime_s(buffer, sizeof(buffer), &tm))
	{
		std::cout << buffer << std::endl;
	}
#else
    struct tm *tm = std::localtime(&now);
    std::cout << asctime(tm) << std::endl;
#endif // _MSC_VER
}