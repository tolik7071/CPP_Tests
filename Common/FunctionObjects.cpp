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
    
    // the copy of f is used
    using std::placeholders::_1;
    std::function<int(int)> c1 = std::bind(&SomeFunctions::cube, f, _1);
    assert(c1(2) == 8);
    
    // the copy of f is used
    using std::placeholders::_2;
    std::function<int(int, int)> c2 = std::bind(&SomeFunctions::multiple, f, _1, _2);
    assert(c2(2, 2) == 4);
    
    std::function<int(int, int)> c3 = std::bind(&SomeFunctions::multiple, &f, _1, _2);
    assert(c3(2, 3) == 6);
}
