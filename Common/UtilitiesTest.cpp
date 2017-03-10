#if defined(_MSC_VER)
#include "stdafx.h"
#endif // _MSC_VER
#include "UtilitiesTest.h"
#include "common.h"

using namespace UtilitiesTest;

template<typename T>
class LimitsOutputter : public std::numeric_limits<T>
{
	public:

	void Print()
	{
		std::cout << typeid(T).name() << " (" << sizeof(T) << ") : ";
		std::cout << "[" << this->lowest() << " .. " << this->max() << "]" << std::endl;
	}
};

void UtilitiesTest::LimitsTest()
{
	LOG_FUNCTION();

	{ LimitsOutputter<int> outputter; outputter.Print(); }
	{ LimitsOutputter<double> outputter; outputter.Print(); }
	{ LimitsOutputter<long double> outputter; outputter.Print(); }
	{ LimitsOutputter<long long> outputter; outputter.Print(); }
	{ LimitsOutputter<unsigned long long> outputter; outputter.Print(); }
}

class A
{
	public:

	A() {}
};

class B : public A
{
	public:

	B(int) : A() {}
};

void UtilitiesTest::CheckConstructorTest()
{
	LOG_FUNCTION();

	LOG_RESULT_OF_BOOL(std::is_default_constructible<A>::value);
	LOG_RESULT_OF_BOOL(std::is_default_constructible<B>::value);
	LOG_RESULT_OF_BOOL(std::is_copy_constructible<B>::value);
}

void UtilitiesTest::CheckTypeTest()
{
    LOG_FUNCTION();
    
	enum class TestColor
	{
		red,
		green,
		blue
	} colors;

	LOG_RESULT_OF_BOOL(std::is_enum<TestColor>::value);
	LOG_RESULT_OF_BOOL(std::is_class<TestColor>::value);
	LOG_RESULT_OF_BOOL(std::is_empty<A>::value);
}
