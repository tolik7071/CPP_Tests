#include "stdafx.h"
#include "LocaleTests.h"
#include <locale>
#include "common.h"

void LocaleTests::LocaleTest()
{
	LOG_FUNCTION();

	std::locale locale = std::locale("russian");
	std::cout << locale.name() << std::endl;
}