/*
Leetcode

problem- Jump Game II

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3732/

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
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len,0);
        for(int i=len-2;i>=0;i--)
        {
            int minValue = INT_MAX-1;
            for(int j=i+1;(j <= i+nums[i]) && j<=len-1;j++)
            {
                
                minValue = min(dp[j],minValue);
                //cout<<"min-"<<minValue<<endl;
            }
            
            dp[i]=minValue+1;
            //cout<<"dp["<<i<<"]-"<<dp[i]<<endl;
        }
        return dp[0];
    }
};
