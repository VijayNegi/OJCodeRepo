/*
Leetcode

problem- Longest Consecutive Sequence

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3769/

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
    int longestConsecutive(vector<int>& nums) {
        
        // unordered_set us(nums.begin(),nums.end());
        // int result = 0;
        // for(auto n:nums)
        // {
        //     if(us.count(n-1)==0)
        //     {
        //         int res = 1;
        //         while(us.count(++n)==1)
        //             ++res;
        //         result = max(res,result);
        //     }
        // }
        // return result;
        
        
        
        // Another solution
        // m will keep the boundry of sequence.
        unordered_map<int, int> m;
        int r = 0;
        for (int i : nums)
        {
            if (m[i]) continue;
            r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
        }
        return r;
        
        }
};
