/*
Leetcode
 problem-     House Robber II

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3494/

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

    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len==1)
            return nums[0];
        
        vector<vector<int>> dp(nums.size(),vector<int>(2,0));
        for(int i=0;i< len-1; i++)
        {
            if(i==0)
            {
                dp[i][1]=nums[i];
            }
            else
            {
                dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
                dp[i][1] = dp[i-1][0]+ nums[i];
            }
        }
        int result = max(dp[len-2][0],dp[len-2][1]);
        for(int i=0;i< len-1; i++)
        {
            if(i==0)
            {
                dp[i][1]=nums[i+1];
            }
            else
            {
                dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
                dp[i][1] = dp[i-1][0]+ nums[i+1];
            }
        }
        result = max(result, max(dp[len-2][0],dp[len-2][1]));

        return result;
    }
};
