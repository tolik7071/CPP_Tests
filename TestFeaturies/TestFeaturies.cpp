#if defined(_MSC_VER)
#include "stdafx.h"
#endif // _MSC_VER
#include "MemoryManagement.h"
#include "UtilitiesTest.h"
#include "DateAndTimeTest.h"
#include "ContainersTests.h"
#include "LocaleTests.h"

int main(int argc, const char * argv[])
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
