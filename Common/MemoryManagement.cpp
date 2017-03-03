#include "stdafx.h"
#include "MemoryManagement.h"
#include "common.h"
#include <memory>
#include <assert.h>

using namespace MemoryManagement;

void MemoryManagement::AutoPtrTest()
{
	LOG_FUNCTION();

	std::auto_ptr<MyData> owner(new MyData());
	std::auto_ptr<MyData> otherOwner;
	otherOwner = owner;
	// now 'otherOwner' has ownership and 'owner' returns nullptr 
	std::cout << (const void *)(owner.get()) << std::endl;

	try
	{
		std::auto_ptr<MyData> owner(new MyData());
		throw 1;
	}
	catch (...)
	{
		;
	}
}

void MemoryManagement::SharedPtrTest()
{
	LOG_FUNCTION();

	std::shared_ptr<MyData> ptr1(new MyData());
	assert(ptr1.get() != nullptr);

	std::shared_ptr<MyData> ptr2 = ptr1;
	assert(ptr2.get() != nullptr);
	assert(ptr1.get() == ptr2.get());

	ptr2.reset();
	assert(ptr2.get() == nullptr);

	ptr1.reset();
	assert(ptr1.get() == nullptr);
}

void MemoryManagement::UniquePtrTest()
{
	LOG_FUNCTION();

	std::unique_ptr<MyData> ptr1 = std::make_unique<MyData>();
	assert(ptr1.get() != nullptr);

	std::unique_ptr<MyData> ptr2 = std::move(ptr1);
	assert(ptr1.get() == nullptr);
	assert(ptr2.get() != nullptr);
}

void MemoryManagement::WeakPtrTest()
{
	LOG_FUNCTION();

	std::shared_ptr<MyData> ptr1 = std::make_shared<MyData>();
	assert(ptr1.get() != nullptr);

	std::weak_ptr<MyData> weakPtr = ptr1;
	assert(weakPtr.lock().get() != nullptr);

	ptr1.reset();
	assert(ptr1.get() == nullptr);
	assert(weakPtr.lock().get() == nullptr);
}

MemoryManagement::MyData::MyData()
{
	LOG_METHOD();
}

MemoryManagement::MyData::~MyData()
{
	LOG_METHOD();
}
