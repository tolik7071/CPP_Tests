#if defined(_MSC_VER)
#include "stdafx.h"
#endif // _MSC_VER
#include "UtilitiesTest.h"
#include "common.h"
#include <string>

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
	};

	LOG_RESULT_OF_BOOL(std::is_enum<TestColor>::value);
	LOG_RESULT_OF_BOOL(std::is_class<TestColor>::value);
	LOG_RESULT_OF_BOOL(std::is_empty<A>::value);
}

void UtilitiesTest::LambdaTest()
{
	auto minLambda = []<typename T>(const T & t1, const T & t2) -> bool
	{
		return t1 < t2;
	};

	assert(false == minLambda(2, 1));
	assert(true == minLambda(2, 10));
	assert(true == minLambda(std::string("A"), std::string("Z")));

	std::vector<std::string> names =
	{
		"1st string.",
		"2nd string.",
		"3rd string."
	};

	auto result = std::find_if(std::begin(names), std::end(names),
		[](const std::string& str) -> bool
		{
			return str == "2nd string.";
		});
	assert(result != std::end(names));
}

struct employee
{
	unsigned id;
	std::string name;
	unsigned salary;
};

void UtilitiesTest::DecompositionTest()
{
	std::pair<std::string, int> pair = std::make_pair("Test string", 10);
	auto &[text, value] = pair;
	assert(text == pair.first && value == pair.second);

	std::vector<employee> employees
	{
		{0, "Jim", 1000},
		{1, "Kate", 2000},
		{2, "Tom", 500}
	};

	for (const auto& [id, name, salary] : employees)
	{
		std::cout << id << " " << name << " " << salary << std::endl;
	}
}

template <typename ... Ts>
auto sum(Ts ... ts)
{
	return (ts + ...);
}

template <typename T, typename ... Ts>
bool within(T min, T max, Ts ...ts)
{
	return ((ts >= min && ts <= max) && ...);
}

void UtilitiesTest::ParameterPackTest()
{
	int s1{ sum(3, 5, 7) };
	assert(s1 == 15);

	std::string s2 = sum(std::string("Hi, "), std::string("world!"));
	assert(s2 == "Hi, world!");

	assert(within(2, 5, 3, 4, 5));
	assert(!within(2, 5, 3, 4, 6));
}