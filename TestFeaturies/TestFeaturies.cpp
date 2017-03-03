#include "stdafx.h"
#include "MemoryManagement.h"
#include "UtilitiesTest.h"
#include "DateAndTimeTest.h"

int main()
{
	MemoryManagement::AutoPtrTest();
	MemoryManagement::SharedPtrTest();
	MemoryManagement::UniquePtrTest();
	MemoryManagement::WeakPtrTest();

	UtilitiesTest::LimitsTest();
	UtilitiesTest::CheckConstructorTest();
	UtilitiesTest::CheckTypeTest();

	DateAndTimeTest::ChronoIntervalTest();
	DateAndTimeTest::DateTimeTests();

    return 0;
}
