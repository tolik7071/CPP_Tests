#if defined(_MSC_VER)
#include "stdafx.h"
#endif // _MSC_VER
#include "MemoryManagement.h"
#include "common.h"
#include <memory>
#include <assert.h>
#include <thread>
#include <mutex>
#include <chrono>

using namespace MemoryManagement;

void MemoryManagement::AutoPtrTest()
{
	LOG_FUNCTION();

	// TODO: remove auto_ptr
	/*
	std::auto_ptr<MyData> owner(new MyData());
	std::auto_ptr<MyData> otherOwner;
	otherOwner = owner;
	assert(owner.get() == nullptr);
	assert(otherOwner.get() != nullptr);

	try
	{
		std::auto_ptr<MyData> owner(new MyData());
		throw 1;
	}
	catch (...)
	{
		;
	}
	*/
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

	std::unique_ptr<MyData> ptr1(new MyData());
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

void Increment(std::mutex &mutex, int &count, unsigned long long ms)
{
	using namespace std::chrono_literals;

	const std::lock_guard<std::mutex> lock(mutex);
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	std::cout << "count: " << ++count << "; in thread #" << std::this_thread::get_id() << ". Wait for " << ms << std::endl;
}

void MemoryManagement::GuardTest()
{
	int count = 0;
	std::mutex mutex;

	std::thread t1(Increment, std::ref(mutex), std::ref(count), 1500);
	std::thread t2(Increment, std::ref(mutex), std::ref(count), 500);
	
	t1.join();
	t2.join();
}