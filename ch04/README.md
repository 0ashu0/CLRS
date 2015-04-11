##Ex4.1-1
 * Return the single greatest one, because :
```cpp
 all elements are negative
 -> line 7 and 14 of FIND-MAX-CROSSING-SUBARRAY will be executed one and only one time
 -> FIND-MAX-CROSSING-SUBARRAY will return (max-left = mid, max-right = mid + 1, left-sum + right-sum = A[mid] + A[mid + 1])
 -> A[mid] + A[mid + 1] must be less than the single element returned by the same level FIND-MAXIMUM-SUBARRAY
 -> finally, an single element with greatest negative value returned.

 //The following recursion tree returns -1
 find[-1,-2,-3,-4,-5,-6,-7,-8] -> -1
 |-find[-1,-2,-3,-4] -> -1
 | |-find[-1,-2] -> -1
 | | |-find[-1] -> -1
 | | |-find[-2] -> -2
 | | |-cros[-1,-2] -> (-1) + (-2) = -3
 | |-find[-3,-4] -> -3
 | | |-find[-3] -> -3
 | | |-find[-4] -> -4
 | | |-cros[-3,-4] -> (-3) + (-4) = -7
 | |-cros[-1,-2,-3,-4] -> (-2) + (-3) = -5
 |-find[-5,-6,-7,-8] -> -5
 | |-find[-5,-6] -> -5
 | | |-find[-5] -> -5
 | | |-find[-6] -> -6
 | | |-cros[-5,-6] -> (-5) + (-6) = -11
 | |-find[-7,-8]  -> -7
 | | |-find[-7] -> -7
 | | |-find[-8] -> -8
 | | |-cros[-7,-8] -> (-7) + (-8) = -15
 | |-cros[-5,-6,-7,-8] -> (-6) + (-7) = -13
 |-cros[-1,-2,-3,-4,-5,-6,-7,-8] (-4) + (-5) = -9
```
 
##Ex4.1-2
  * Pseudocode:
```cpp
//T(n) = theta(n^2)
Find-Max-Profit-Brutally(prices)
  def max = tuple(buy = 0, sell = 1)
  if prices.length > 1
    for b = 0 to prices.lengh - 1
      for s = b + 1 to prices.lengh - 1
        if prices[s] - prices[b] > prices[max.sell] - prices[max.buy]
          max = tuple(b, s)
  return max
```

##Ex4.1-3 [Implementation](src/maximum_subarray.hpp#L10-L92) | [Test](src/maximum_subarray.hpp#L10-L92)
 * On my desktop, Windows 8 + Visual Studio 2013, the crossover point occurs at n0 = 100. At this point, both alorithm used around 1 ms to run. I didn't carry out furture experiment,as it is quite time consuming. Just guess that using Brute-Force as base case for recursion would not change the crossover point.

##Ex4.1-4
 * Add the following line into FIND-MAXIMUM-SUBARRAY between line 6 and line 7:
```cpp
//-1 indicate this is an empty subarray
if 0 >= max(left_sum, right_sum, cross_sum)
 return (-1,1,0)
```
##Ex4.1-5 [Implementation](src/maximum_subarray.hpp#L94-L115) | [Test](test/test_maximum_subarray.cpp#L135-L163)
 * The idea given is actually [Kadane's algorithm](http://en.wikipedia.org/wiki/Maximum_subarray_problem) an example of Dynamic Programming. 

## Ex4.3-1
```cpp
 Guess : 
  for a constant c, T(n) <= c(n - 1)^2 + n
 Pick c = 1
  (n - 1)^2 + n = n^2 - n + 1 <= , for n >= 1 

```
