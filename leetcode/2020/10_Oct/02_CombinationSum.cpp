/*
Leetcode
problem-     Combination Sum

Link - https://leetcode.com/explore/featured/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3481/
        
tags - Straightforward Backtracking (Unbounded Knapsack)

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
    
    void helper(vector<int>& candidates, int target,int index,vector<vector<int>>& combinations, vector<int>& current)
    {
        if(target==0)
        {
            combinations.push_back(current);
            return;
        }
        if(target<0 || index >= candidates.size()) return;
        current.push_back(candidates[index]);
        helper(candidates,target-candidates[index], index, combinations, current);
        current.pop_back();
        helper(candidates,target, index +1, combinations, current);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
#if 0
        vector<vector<int>> result;
        vector<int> dp(target+1,0);
        
        int num=1;
        for(auto n: candidates)
            {
                
                dp[n] = 1;
            }
        
        while(num<=target)
        {
            for(auto n: candidates)
            {
                if(num - n>0)
                    dp[num] += dp[num-n];
            }
            num++;
        }
        
        for(auto a:dp)
        {
            cout<<" "<<a;
        }
        //cout<<dp[target];
        return result;
#endif
        vector<vector<int>> result;
        vector<int> curr;
        helper(candidates,target,0,result,curr);
        return result;
        
    }
};
