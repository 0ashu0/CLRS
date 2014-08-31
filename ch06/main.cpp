#include <vector>
#include <iostream>
#include "../misc/alan.hpp"
#include "heap.hpp"

int main()
{
    std::vector<int> v {4,1,3,2,16,9,10,14,8,7};
    clrs::ch6::build_heap(v.begin(), v.end());
    alan::print_container(v);

    alan::end();
    return 0;
}
