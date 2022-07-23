#if defined(_MSC_VER)
#include "stdafx.h"
#endif // _MSC_VER
#include "MemoryManagement.h"
#include "UtilitiesTest.h"
#include "DateAndTimeTest.h"
#include "ContainersTests.h"
#include "LocaleTests.h"
#include "StreamTests.h"
#include "FunctionObjects.hpp"
#include <initializer_list>
#include "RTTI_Tests.h"
#include "PathTests.h"
#include "UserDefinedLiterals.h"

int main(int argc, const char * argv[])
{
	MemoryManagement::AutoPtrTest();
	MemoryManagement::SharedPtrTest();
	MemoryManagement::UniquePtrTest();
	MemoryManagement::WeakPtrTest();
	MemoryManagement::GuardTest();

	UtilitiesTest::LimitsTest();
	UtilitiesTest::CheckConstructorTest();
	UtilitiesTest::CheckTypeTest();
	UtilitiesTest::LambdaTest();
	UtilitiesTest::DecompositionTest();
	UtilitiesTest::ParameterPackTest();

	DateAndTimeTest::ChronoIntervalTest();
	DateAndTimeTest::DateTimeTests();
	DateAndTimeTest::CastingIntervalsTest();

	ContainersTests::ArrayTests();
	ContainersTests::MapTests();
	ContainersTests::SetTests();
	ContainersTests::IteratorsTests();
	ContainersTests::RemoveElementFromVector();

	LocaleTests::LocaleTest();

	StreamTests::StringStreamTest();
    
    FunctionObjects::NonMembersCall();
    FunctionObjects::StaticCall();
    FunctionObjects::MembersCall();

	RTTI_TESTS::DynamicCastTest();

	PathTests::PathTests();

	UserDefinedLiterals::LiteralsTest();

    return 0;
}
