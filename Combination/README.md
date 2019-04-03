
## Problem

Write a recursive algorithm in pseudo-code to calculate C(n,k), the number of k-combinations (i.e., k-element subsets) of an n-element set.

### Formula

* C(n, k) = C(n-1, k-1) + C(n-1, k) valid for 1 ≤ k ≤ n-1,  and
* C(n, n) = C(n, 0) = 1 valid for n ≥ 0.

## Pseudo-code using Recursive 

CALCULATE_COMBINATIONS(n, k)

1. if n is great or equal to 0 then
2.  if k is equal to n or 0 then 
3.   return 1
4. if k is greater than 0 and less than n then
5.  return CALCULATE_COMBINATIONS(n-1, k-1) + CALCULATE_COMBINATIONS(n-1, k);

## Pseudo-code using Dynamic Programming

CALCULATE_COMBINATIONS(n, k)

1. for i <- 1 to k
2.  m[i,i] <- 1
3. for i <- 0 to n
4.  m[i, 0] <- 1
5. for i <- 2 to n
6.  for j <- 1 to k
7.   m[i,j] <- m[i-1, j-1] + m[i-1, j]


