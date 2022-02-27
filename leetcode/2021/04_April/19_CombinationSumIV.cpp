/*
Leetcode

 problem- Combination Sum IV

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3713/

tags - Linked list

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
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target+1,0);
        dp[0]=1; // if we find same amount in nums we can use it.
        int currVal=0;
        while(currVal<=target)
        {
            for(int i=0;i<nums.size();i++)
            {
                int remainingVal = currVal - nums[i];
                if(remainingVal>=0)
                    dp[currVal]+=dp[remainingVal];
            }
            ++currVal;
        }
        
        return dp[target];
    }
};
