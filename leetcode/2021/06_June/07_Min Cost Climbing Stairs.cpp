/*
Leetcode

problem- Min Cost Climbing Stairs

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3770/

tags - Easy
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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2;i<n;i++)
        {
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        dp[n] = min(dp[n-1],dp[n-2]);
        return dp[n];
    }
};
