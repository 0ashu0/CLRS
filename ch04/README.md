##Ex4.1-1
 * The pseudocode FIND-MAX-CROSSING-SUBARRAY didn't show how to initialize variables `max-left` and `max-right`, so technically it's imporssible to determine what will be returned for such case. For real implementation, however, FIND-MAXIMUM-SUBARRAY is supposed to return the single greatest item in the all-negative array. 
 
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
