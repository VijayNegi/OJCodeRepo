/*
Leetcode

problem- 1911. Maximum Alternating Subsequence Sum

Link - https://leetcode.com/problems/maximum-alternating-subsequence-sum/

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

typedef long long ll;
class Solution {
    vector<vector<ll>> dp;
    ll helper(vector<int>& num,int idx,bool even)
    {
        if(idx>=num.size())
            return 0;
        if(even && dp[idx][0]>=0)
            return dp[idx][0];
        else if(!even && dp[idx][1]>=0)
            return dp[idx][1];
            
        ll skip = helper(num,idx+1,even);
        
        if(even)
        {
            ll e = helper(num,idx+1,!even);
            e += num[idx];
            dp[idx][0] = max(e,skip);
            return dp[idx][0];
        }
        else
        {
            ll o = helper(num,idx+1,!even);
            o-=num[idx];
            dp[idx][1] = max(o,skip);
            return dp[idx][1];
        }
        return 0;
    }
public:
    long long maxAlternatingSum1(vector<int>& nums) {
        dp = vector(nums.size(),vector<ll>(2,-1));
        ll result = helper(nums,0,true);
        return result;
    }
    long long maxAlternatingSum(vector<int>& A) {
        long long odd = 0, even = 0;
        for (int& a: A)
        {
            even = max(even, odd + a);
            odd = even - a;
        }
        return even;
    }
    long long maxAlternatingSum3(vector<int>& A) {
        long res = A[0];
        for (int i = 1; i < A.size(); ++i)
            res += max(A[i] - A[i-1], 0);
        return res;
    }
    long long maxAlternatingSum4(vector<int>& nums) {
        long long n = nums.size(), i, j, k, ans;
        vector<long long> dp0(n + 1, -1), dp1(n + 1, -1);
        dp0[0] = 0;

        for (i = 1; i <= n; i++) {
            dp0[i] = max(dp0[i - 1], dp1[i - 1] - nums[i - 1]);
            dp1[i] = max(dp1[i - 1], dp0[i - 1] + nums[i - 1]);
        }

        ans = max(dp0[n], dp1[n]);
        return ans;
    }
};
