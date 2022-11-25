#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.2.іт/lab_7.2.іт.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72it
{
	TEST_CLASS(UnitTest72it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int count = 0;
            int s = 0;
            int result;
            const int rowCOUNT = 4;
            const int colCOUNT = 4;
            int a[rowCOUNT][colCOUNT] = {
              {1, 5, 8, 10},
              {2, 15, 7, 9},
              {-1, -2, 4, 0},
              {-3, 4, 6, 9}
            };
            int* pa[4] = { a[0], a[1], a[2], a[3] };
            Max(pa, rowCOUNT, colCOUNT, );
            result = count;
            Assert::AreEqual(9, result);

		}
	};
}
