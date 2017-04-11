#if defined(_MSC_VER)
#include "stdafx.h"
#endif // _MSC_VER
#include "LocaleTests.h"
#include <locale>
#include "common.h"

void LocaleTests::LocaleTest()
{
	LOG_FUNCTION();

    std::locale locale = std::locale::classic();
	std::cout << locale.name() << std::endl;
    
    locale.messages
}
