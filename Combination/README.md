
## Problem

Write a recursive algorithm in pseudo-code to calculate C(n,k), the number of k-combinations (i.e., k-element subsets) of an n-element set.

### Formula

* C(n, k) = C(n-1, k-1) + C(n-1, k) valid for 1 ≤ k ≤ n-1,  and
* C(n, n) = C(n, 0) = 1 valid for n ≥ 0.

## Pseudo-code using Recursive 

    CALCULATE_COMBINATIONS(n, k)

    if n is great or equal to 0 then
        if k is equal to n or 0 then 
            return 1
    if k is greater than 0 and k is less than n then
        return CALCULATE_COMBINATIONS(n-1, k-1) + CALCULATE_COMBINATIONS(n-1, k)

## Pseudo-code using Dynamic Programming

    CALCULATE_COMBINATIONS(n, k)

    for i <- 1 to k
        m[i,i] <- 1
    for i <- 0 to n
        m[i, 0] <- 1
    for i <- 2 to n
        for j <- 1 to k
            m[i,j] <- m[i-1, j-1] + m[i-1, j]

## Dynamic Programming Code의 Time Complexity

 - 반복문 두개로 끝나고 n번을 k번 돌기 때문에 nk + k + n 이다.
 - 이 때 k의 최대가 n이기 때문에 세타(n^2)라고 봐도 무방하다.
 
 ## 효율성 비교
 
     put n, k value : 20 10
     recursive result : 184756, time : 2674ms
     dynamic result   : 184756, time : 13ms
     
- 압도적으로 dynamic programming 사용한 경우가 빠르다.

