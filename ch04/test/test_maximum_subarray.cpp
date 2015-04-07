#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/maximum_subarray.hpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{		
	TEST_CLASS(maximum_subarray)
	{
	public:
		
		TEST_METHOD(find_max_profit_brutally_case1)
		{
			auto prices = std::vector < int > { 1, -2, 3 };
			auto actual = clrs::ch04::find_max_profit_brutally(prices);
			Assert::AreEqual(1u, actual.first);
			Assert::AreEqual(2u, actual.second);
		}

		TEST_METHOD(find_max_profit_brutally_case2)// the case as shown in CLRS
		{
			auto prices = std::vector < int > { 100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
			auto actual = clrs::ch04::find_max_profit_brutally(prices);
			Assert::AreEqual(7u, actual.first);
			Assert::AreEqual(11u, actual.second);
		}
	};
}