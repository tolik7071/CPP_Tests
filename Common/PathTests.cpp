#include "PathTests.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <assert.h>

namespace fs = std::filesystem;

void PathTests::PathTests()
{
/*
	fs::path currentPath(fs::current_path());
	std::cout << "Current path: " << currentPath << std::endl;

	fs::path combinedPath(currentPath);
	combinedPath.append("test.cpp");
	std::cout << "Combined path (append test.cpp): " << combinedPath << std::endl;
	std::cout << (currentPath / "data" / "test2.cpp").u8string() << std::endl;
*/

	fs::path outputFileName(fs::temp_directory_path().concat("test.bin"));
	
	if (fs::exists(outputFileName))
	{
		fs::remove(outputFileName);
	}

	std::ofstream outputStream;
	outputStream.open(outputFileName);
	assert(outputStream.is_open());

	outputStream << "This is a test string!";
	outputStream.flush();
	outputStream.close();

	for (auto &element : fs::directory_iterator(fs::temp_directory_path()))
	{
		if (element.is_regular_file() && element.path() == outputFileName)
		{
			std::cout << fs::absolute(element.path()) << std::endl;
			break;
		}
	}
}
