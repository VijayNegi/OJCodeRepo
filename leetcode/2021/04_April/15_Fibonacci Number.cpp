/*
Leetcode

 problem- Fibonacci Number

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3709/

tags - 

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <utility>
#include <vector>
#include <deque>
#include <map>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;

class Solution {
public:
    int fib(int n) {
        std::vector<int> dp(n+2,-1);
        dp[0]=0;
        dp[1]=1;
        int i=1;
        while(++i<=n)
        {
            dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n];
    }
};
