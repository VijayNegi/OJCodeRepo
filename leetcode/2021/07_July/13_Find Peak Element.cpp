/*
Leetcode

problem- Find Peak Element

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3812/

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
    int findPeakElement1(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        if(nums[0]>nums[1])
            return 0;
        if(nums[n-1]>nums[n-2])
            return n-1;
        bool flag = true;
        for(int i=0;i<n-1;++i)
        {
            if(nums[i]<nums[i+1] )
                flag = true;
            else if(flag && nums[i]>nums[i+1])
                return i;
            else
                flag = false;
        }
        return -1;
    }
    // Impliment binary search using this property. i.e. to find local maxima.
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        if(nums[0]>nums[1])
            return 0;

        for(int i=0;i<n-1;++i)
        {
            if(nums[i]>nums[i+1] )
                return i;
        }
        return n-1;
    }
};
