#if defined(_MSC_VER)
#include "stdafx.h"
#endif // _MSC_VER
#include "ContainersTests.h"
#include "common.h"
#include <array>
#include <string>
#include <assert.h>
#include <map>
#include <memory>
#include <algorithm>
#include <set>

using namespace ContainersTests;

template <typename T>
void PrintElements(const std::vector<T> &v)
{
	typename std::vector<T>::const_iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

template <typename T>
void QuickRemoveAt(std::vector<T>& v, std::size_t index)
{
	if (index < v.size())
	{
		v[index] = std::move(v.back());
		v.pop_back();
	}
}

template <typename T>
void QuickRemoveAt(std::vector<T>& v, typename std::vector<T>::iterator it)
{
	if (it != v.end())
	{
		*it = std::move(v.back());
		v.pop_back();
	}
}

void ContainersTests::ArrayTests()
{
	LOG_FUNCTION();

	typedef std::array<std::string, 3> TThreeStrings;
	
	TThreeStrings strings = { "String 1", "String 2", "String 3" };
	
	TThreeStrings::const_pointer ptr = strings.data();
	assert(strcmp(ptr->data(), "String 1") == 0);

	ptr++;
	assert(strcmp(ptr->data(), "String 2") == 0);

	ptr++;
	assert(strcmp(ptr->data(), "String 3") == 0);
}

void ContainersTests::MapTests()
{
	LOG_FUNCTION();

	typedef std::map<int, std::shared_ptr<std::string> > TStringMap;

	TStringMap strings;

	for (int i = 0; i < 10; i++)
	{
		TStringMap::value_type pair = std::make_pair(i, std::shared_ptr<std::string>(new std::string(std::to_string(i))));
		strings.insert(pair);
	}

	std::for_each(strings.begin(), strings.end(),
		[](const TStringMap::value_type& pair)
		{
			std::cout << pair.first << ": " << *(pair.second.get()) << std::endl;
		}
	);

	int index = 5;
	TStringMap::const_iterator iterator = std::find_if(strings.begin(), strings.end(),
		[index](const TStringMap::value_type& pair) -> bool
		{
			return pair.first == index;
		}
	);

	assert((*iterator).first == index);
	assert((*iterator).second->compare(std::string(std::to_string(index))) == 0);
}

void ContainersTests::SetTests()
{
	std::set<int> numbers =
	{
		5, 1, 0, 5, 11, 0
	};

	//for (auto& value : numbers)
	//{
	//	std::cout << value << std::endl;
	//}

	assert(numbers.size() == 4);

	std::multiset<int> numbers2 =
	{
		5, 1, 0, 5, 11, 0
	};

	assert(numbers2.size() == 6);
}

void ContainersTests::IteratorsTests()
{
	std::vector<char> str = { 'T', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g' };
	{
		std::vector<char>::const_iterator it = str.begin();
		while (it != str.end())
		{
			std::cout << *it;
			it++;
		}
		std::cout << std::endl;
	}
	{
		std::vector<char>::const_reverse_iterator it = str.rbegin();
		while (it != str.rend())
		{
			std::cout << *it;
			it++;
		}
		std::cout << std::endl;
	}
}

void ContainersTests::RemoveElementFromVector()
{
	std::vector<int> numbers{ -8, 5, 3, 0, 11, -1 };
	PrintElements(numbers);

	// remove 11
	auto result = std::find(numbers.begin(), numbers.end(), 11);
	std::cout << *result << std::endl;
	if (result != numbers.end())
	{
		QuickRemoveAt(numbers, result);
	}
	PrintElements(numbers);

	// remove 0
	QuickRemoveAt(numbers, 3);
	PrintElements(numbers);
}