#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/maximum_subarray.hpp"
#include <vector>
#include <random>

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

		TEST_METHOD(find_max_subarray_case1)
		{
			auto changes = std::vector < int > {-1, -2, 3, 4, 5, 6, 7, -8};
			auto head = std::vector<int>::size_type{};
			auto tail = std::vector<int>::size_type{};
			auto summ = std::vector<int>::value_type{};
			std::tie(head, tail, summ) = clrs::ch04::find_max_subarray(changes, 0u, 7u);

			Assert::AreEqual(2u, head);
			Assert::AreEqual(6u, tail);
			Assert::AreEqual(25, summ);
		}

		TEST_METHOD(find_max_subarray_case2)
		{
			auto changes = std::vector < int > {42};
			auto head = std::vector<int>::size_type{};
			auto tail = std::vector<int>::size_type{};
			auto summ = std::vector<int>::value_type{};
			std::tie(head, tail, summ) = clrs::ch04::find_max_subarray(changes, 0u, 0u);

			Assert::AreEqual(0u, head);
			Assert::AreEqual(0u, tail);
			Assert::AreEqual(42, summ);
		}

		TEST_METHOD(find_max_subarray_case3)
		{
			auto changes = std::vector < int > {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
			auto head = std::vector<int>::size_type{};
			auto tail = std::vector<int>::size_type{};
			auto summ = std::vector<int>::value_type{};
			std::tie(head, tail, summ) = clrs::ch04::find_max_subarray(changes, 0u, changes.size() - 1);

			Assert::AreEqual(7u, head);
			Assert::AreEqual(10u, tail);
			Assert::AreEqual(43, summ);
		}

		//
		//Ex 4.1-3
		//
		template<typename Integer>
		auto make_random_data(Integer min, Integer max, std::size_t size) -> std::vector < Integer >
		{
			auto generate = [=] 
			{
				auto static engine = std::default_random_engine{};
				auto static distribution = std::uniform_int_distribution<Integer>(min, max);
				return distribution(engine);
			};

			auto data = std::vector<Integer>(size);
			for (auto& elem : data) elem = generate();

			return data;
		}

		TEST_METHOD(brute_force) //1ms
		{
			auto data = make_random_data(-20, 20, 100);
			clrs::ch04::find_max_profit_brutally(data);
		}

		TEST_METHOD(divide_conquer) //<1ms
		{
			auto data = make_random_data(-20, 20, 100);
			clrs::ch04::find_max_subarray(data, 0u, data.size() - 1);
		}

		//
		//	Ex 4.1-5
		//	Test for Kadane's algorithm	
		//
		TEST_METHOD(kadane_case1)
		{
			auto changes = std::vector < int > {-1, 2, 3, -8};
			auto head = std::vector<int>::size_type{};
			auto tail = std::vector<int>::size_type{};
			auto summ = std::vector<int>::value_type{};
			std::tie(head, tail, summ) = clrs::ch04::kadane(changes);

			Assert::AreEqual(1u, head);
			Assert::AreEqual(2u, tail);
			Assert::AreEqual(5, summ);
		}

		TEST_METHOD(kadane_case2)
		{
			auto changes = std::vector < int > {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
			auto head = std::vector<int>::size_type{};
			auto tail = std::vector<int>::size_type{};
			auto summ = std::vector<int>::value_type{};
			std::tie(head, tail, summ) = clrs::ch04::kadane(changes);

			Assert::AreEqual(7u, head);
			Assert::AreEqual(10u, tail);
			Assert::AreEqual(43, summ);
		}
	};
}