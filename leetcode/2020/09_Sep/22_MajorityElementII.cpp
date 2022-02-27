/*
Leetcode
 problem-   Majority Element II

Link - https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3469/
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
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result(2,0);
        vector<int> count(2,0);
        
        for(auto a:nums)
        {
            if(result[0]==a)
                ++count[0];
            else if(result[1]==a)
                ++count[1];
            else if(!count[0])
            {
                result[0]=a;
                ++count[0];
            }
            else if(!count[1])
            {
                result[1]=a;
                ++count[1];
            }
            else
            {
                --count[0];
                --count[1];
            }
        }
        count[0] = count[1] = 0;
        for (auto a:nums)
          if (result[0]==a)  ++count[0];
          else if (result[1]==a)  ++count[1];
        vector<int> r;
        if (count[0] > nums.size()/3) r.push_back(result[0]);
        if (count[1] > nums.size()/3) r.push_back(result[1]);
        return r;

    }
};
