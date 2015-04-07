##Ex4.1-1
 * Return the single greatest one, because :
```cpp
 all elements are negative
 -> line 7 and 14 of FIND-MAX-CROSSING-SUBARRAY will be executed one and only one time
 -> FIND-MAX-CROSSING-SUBARRAY will return (max-left = mid, max-right = mid + 1, left-sum + right-sum = A[mid] + A[mid + 1])
 -> A[mid] + A[mid + 1]) must be less than the single element returned by the same level FIND-MAXIMUM-SUBARRAY
 -> finally, an single element with greatest negative value will be returned.

 E.G. the following recursion tree returns -1
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
