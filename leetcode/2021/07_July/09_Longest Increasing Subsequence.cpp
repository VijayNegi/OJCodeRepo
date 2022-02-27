/*
Leetcode

problem- Longest Increasing Subsequence

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3808/

tags - Medium
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

//https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
class Solution {
public:
    // n2 solution
    int lengthOfLIS1(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int result = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[j]<nums[i])
                    dp[i] = max(dp[i],dp[j] + 1);
            }
            result = max(dp[i],result);
        }
        return result;
    }
    // also n2 solution but this can be optimized as we are just finding position a[i] in sorted array.
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,INT_MAX);
        dp[0] = INT_MIN;
        int result = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(dp[j-1] < nums[i] && dp[j]> nums[i])
                {
                    dp[j] = nums[i];
                    result = max(result, j);
                }
            }
        }
        
        return result;
    }
    // nlogn solution
    int lengthOfLIS3(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,INT_MAX);
        dp[0] = INT_MIN;
        int result = 0;
        for(int i=0;i<n;++i)
        {
            int j = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if(dp[j-1] < nums[i] && dp[j]> nums[i])
            {
                dp[j] = nums[i];
                result = max(result, j);
            }
        }
        
        return result;
    }
    // just clean way of writing above
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // O(nlogn) binary search store LIS
        vector<int> lis;
        
        for (auto &num : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), num);
            
            if (it == lis.end()) {
                lis.push_back(num);
            }
            else {
                *it = num;
            }
        }
        
        return lis.size();
    }
};
