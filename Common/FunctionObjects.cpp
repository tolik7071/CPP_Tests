//
//  FunctionObjects.cpp
//  CPP_Tests
//
//  Created by tolik7071 on 4/15/17.
//  Copyright © 2017 tolik7071. All rights reserved.
//

#if defined(_MSC_VER)
#include "stdafx.h"
#endif // _MSC_VER
#include "FunctionObjects.hpp"
#include "common.h"
#include <functional>
#include <assert.h>

using namespace std::placeholders;

static int Multiple(int value1, int value2)
{
    return value1 * value2;
}

void FunctionObjects::NonMembersCall()
{
    std::function<int(int)> c1 = [](int value) -> int { return value * value; };
    assert(c1(2) == 4);
    
    std::function<int()> c2 = std::bind(&Multiple, 3, 4);
    assert(c2() == 12);
}

namespace FunctionObjects
{
    struct SomeFunctions
    {
        SomeFunctions()
        {
        }
        
        SomeFunctions(const SomeFunctions&)
        {   
        }
        
        static void F()
        {
            LOG_FUNCTION();
        }
        
        int cube(int value)
        {
            return value * value * value;
        }
        
        int multiple(int value1, int value2)
        {
            return value1 * value2;
        }

		//template<typename... T>
		//T multiple(const T... args)
		//{
		//	T result = T();

		//	std::initializer_list<std::string> arguments = { args... };
		//	std::initializer_list<std::string>::iterator it = arguments.begin();
		//	for (; it != arguments.end(); ++it)
		//	{
		//		//result *= *it;
		//	}

		//	return result;
		//}
    };
}

void FunctionObjects::StaticCall()
{
    LOG_FUNCTION();
    
    std::function<void()> c1 = &SomeFunctions::F;
    c1();
}

void FunctionObjects::MembersCall()
{
    SomeFunctions f;
    
    typedef std::function<int(int)> TFunction1;
    // the copy of f is used
    using std::placeholders::_1;
    TFunction1 c1 = std::bind(&SomeFunctions::cube, f, _1);
    TFunction1::result_type result1 = c1(2);
    assert(result1 == 8);
    
    typedef std::function<int(int, int)> TFunction2;
    // the copy of f is used
    using std::placeholders::_2;
    TFunction2 c2 = std::bind(&SomeFunctions::multiple, f, _1, _2);
    TFunction2::result_type result2 = c2(2, 2);
    assert(result2 == 4);
    
    typedef std::function<int(int, int)> TFunction3;
    TFunction3 c3 = std::bind(&SomeFunctions::multiple, &f, _1, _2);
    TFunction3::result_type result3 = c3(2, 3);
    assert(result3 == 6);
}
