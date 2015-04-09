#pragma once
#include <utility>
#include <tuple>
#include <algorithm>

namespace clrs
{
	namespace ch04
	{
		template<typename Container>
		std::pair<typename Container::size_type, typename Container::size_type>
			find_max_profit_brutally(Container const& prices)
		{
			using Pair = std::pair < typename Container::size_type, typename Container::size_type > ;
			using Size = typename Container::size_type;

			auto max = Pair{ 0, 1 };
			if (prices.size() > 1)
				for (auto b = Size(0); b != prices.size(); ++b)
					for (auto s = Size(b + 1); s != prices.size(); ++s)
						if (prices[s] - prices[b] > prices[max.second] - prices[max.first])
							max = Pair{ b, s };
			return max;
		}

		//prices.size must be greater than 1, value_type must be signed
		template<typename Container>
		Container convert_to_changes(Container const& prices)
		{
			auto changes = Container(prices.size() - 1);
			for (int i = 0; i != changes.size(); ++i)
				changes[i] = prices[i + 1] - prices[i];
			return changes;
		}

		template<typename C>
		std::tuple<typename C::size_type, typename C::size_type, typename C::value_type>
			find_max_crossing_subarray(C const& arr, typename C::size_type low, typename C::size_type mid, typename C::size_type hgh)
		{
			auto accumulation = typename C::value_type{};

			auto lft_sum = accumulation = arr[mid];
			auto max_lft = mid;
			if (low == mid) goto Lft_done;
			for (auto i = mid - 1; i != low - 1; --i)
			{
				if ((accumulation += arr[i]) > lft_sum)
				{
					lft_sum = accumulation;
					max_lft = i;
				}
			}
Lft_done:

			auto rht_sum = accumulation = arr[mid + 1];
			auto max_rht = mid + 1;
			if (low == mid) goto Rht_done;
			for (auto i = mid + 2; i != hgh + 1; ++i)
			{
				if ((accumulation += arr[i]) > rht_sum)
				{
					rht_sum = accumulation;
					max_rht = i;
				}
			}
			
Rht_done:

			return std::make_tuple(max_lft, max_rht, lft_sum + rht_sum);
		}

		template<typename C>
		auto find_max_subarray(C const& arr, typename C::size_type low, typename C::size_type hgh)
			-> std::tuple < typename C::size_type, typename C::size_type, typename C::value_type >
		{
			if (low == hgh)
				return std::make_tuple(low, hgh, arr[low]);
			
			auto mid = (low + hgh) / 2;
			auto lft = find_max_subarray(arr, low, mid);
			auto rht = find_max_subarray(arr, mid + 1, hgh);
			auto crs = find_max_crossing_subarray(arr, low, mid, hgh);
			auto rht_max = std::get<2>(rht);
			auto lft_max = std::get<2>(lft);
			auto crs_max = std::get<2>(crs);
			auto max = std::max({ lft_max, rht_max, crs_max });
			
			return max == crs_max ? crs : max == lft_max ? lft : rht;
		}
	}
}