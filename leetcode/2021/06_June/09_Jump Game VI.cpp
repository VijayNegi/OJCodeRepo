/*
Leetcode

problem- Jump Game VI

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3773/

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

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size()+1);
        multiset<int> ms;
        ms.insert(nums[0]);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(ms.size()>k)
            {
                ms.erase(ms.find(dp[i-k-1]));
            }
            
            dp[i] = *ms.rbegin() + nums[i];
            ms.insert(dp[i]);
           
            //cout<<"dp "<<i<<"="<<dp[i]<<endl;
        }
        return dp[nums.size()-1];
    }
};
