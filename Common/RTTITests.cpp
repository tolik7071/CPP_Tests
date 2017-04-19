#if defined(_MSC_VER)
#include "stdafx.h"
#endif // _MSC_VER
#include "RTTI_Tests.h"
#include "common.h"
#include <memory>
#include <assert.h>

namespace RTTI_TESTS
{
	struct A
	{
		int a;

		virtual void print() const
		{
			LOG_METHOD();
			std::cout << a << std::endl;
		}
	};
	
	struct B
	{
		int b;

		virtual void print() const
		{
			LOG_METHOD();
			std::cout << b << std::endl;
		}
	};
	
	struct C : public A, public B
	{
		virtual void print() const
		{
			LOG_METHOD();
			std::cout << a << ", " << b << std::endl;
		}
	};
}

void RTTI_TESTS::DynamicCastTest()
{
	LOG_FUNCTION();
	
	C *ptr = new C();
	ptr->print();

	const void * ptrToB = dynamic_cast<B*>(ptr);
	const void * ptrToA = dynamic_cast<A*>(ptr);
	
	// dynamic_cast (and static_cast) can change an address
	assert(ptrToB > ptrToA);
	assert(ptr == ptrToA);

	reinterpret_cast<const A*>(ptrToA)->print();
	reinterpret_cast<const B*>(ptrToB)->print();

	delete ptr;
}
