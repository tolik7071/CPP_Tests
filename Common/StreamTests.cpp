
#if defined(_MSC_VER)
#include "stdafx.h"
#endif // _MSC_VER
#include "StreamTests.h"
#include "common.h"
#include <iostream>
#include <sstream>
#include <string>

void StreamTests::StringStreamTest()
{
	LOG_FUNCTION();

	std::stringstream text;
	text << "This is a text...";
	text << "\n";
	text << "and, other text on a new line";
	text << "\n";
	text << 25.669;
	std::cout << text.str() << std::endl;
}
