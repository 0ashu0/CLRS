#pragma once
#include <utility>

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
	}
}