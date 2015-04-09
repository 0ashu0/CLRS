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

		TEST_METHOD(convert_to_changes_case1)
		{
			auto prices = std::vector < int > { 100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
			auto actual = clrs::ch04::convert_to_changes(prices);
			auto expect = std::vector < int > {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
			Assert::IsTrue(expect == actual);
		}

		TEST_METHOD(find_max_crossing_subarray_case1)
		{
			auto changes = std::vector < int > {-1, 2, 3, -8};
			auto head = std::vector<int>::size_type{};
			auto tail = std::vector<int>::size_type{};
			auto summ = std::vector<int>::value_type{};
			std::tie(head, tail, summ) = clrs::ch04::find_max_crossing_subarray(changes, 0u, 1u, 3u);

			Assert::AreEqual(1u, head);
			Assert::AreEqual(2u, tail);
			Assert::AreEqual(5 , summ);
		}

		TEST_METHOD(find_max_crossing_subarray_case2)
		{
			auto changes = std::vector < int > {-1, -2, 3, 4, 5, 6, 7, -8};
			auto head = std::vector<int>::size_type{};
			auto tail = std::vector<int>::size_type{};
			auto summ = std::vector<int>::value_type{};
			std::tie(head, tail, summ) = clrs::ch04::find_max_crossing_subarray(changes, 0u, 3u, 7u);

			Assert::AreEqual(2u, head);
			Assert::AreEqual(6u, tail);
			Assert::AreEqual(25, summ);
		}
	};
}