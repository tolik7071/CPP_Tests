#pragma once

namespace MemoryManagement
{
	void AutoPtrTest();
	void SharedPtrTest();
	void UniquePtrTest();
	void WeakPtrTest();
	void GuardTest();

	class MyData
	{
		public:

		MyData();
		virtual ~MyData();
	};
}
