/*
Leetcode

problem- 1909. Remove One Element to Make the Array Strictly Increasing
 Similar to - 665. Non-decreasing Array

Link - https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/

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
    bool canBeIncreasing(vector<int>& nums) {
        int change=0;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
            {
                if(change==1)
                    return false;
                change++;
                if(i>1 && nums[i-2]<=nums[i] )
                    nums[i-1]= nums[i];
                else if(i>1 && nums[i-2]>nums[i])
                    nums[i]= nums[i-1];
            }
        }
        return change<2;
    }
};
