/*
Leetcode

problem- 1. Two Sum

Link - https://leetcode.com/problems/two-sum/

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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();++i)
        {
            auto it = m.find(target - nums[i]);
            if(it != m.end())
                return {it->second,i};
            else
                m[nums[i]] = i;
        }
        
        return {0,0};
    }
};
