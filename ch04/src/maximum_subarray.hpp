#pragma once
#include <utility>
#include <tuple>

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

		//len(prices) must be greater than 1, value_type must be signed
		template<typename Container>
		Container convert_to_changes(Container const& prices)
		{
			auto changes = Container(prices.size() - 1);
			for (int i = 0; i != changes.size(); ++i)
				changes[i] = prices[i + 1] - prices[i];
			return changes;
		}

		template<typename Container>
		std::tuple<typename Container::size_type, typename Container::size_type, typename Container::value_type>
			find_max_crossing_subarray(Container const& arr, Container::size_type low, Container::size_type mid, Container::size_type hgh)
		{

		}
	}
}