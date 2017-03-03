#pragma once

namespace MemoryManagement
{
	void AutoPtrTest();
	void SharedPtrTest();
	void UniquePtrTest();
	void WeakPtrTest();

	class MyData
	{
		public:

			MyData();
			virtual ~MyData();
	};
}
