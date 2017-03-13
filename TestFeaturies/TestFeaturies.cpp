#include "stdafx.h"
#include "MemoryManagement.h"
#include "UtilitiesTest.h"
#include "DateAndTimeTest.h"
#include "ContainersTests.h"
#include "LocaleTests.h"

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

	ContainersTests::ArrayTests();
	ContainersTests::MapTests();

	LocaleTests::LocaleTest();

    return 0;
}
