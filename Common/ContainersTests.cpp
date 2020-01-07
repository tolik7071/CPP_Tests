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

using namespace ContainersTests;

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
