/*
Leetcode
 problem-     Binary Search

Link - https://leetcode.com/problems/binary-search/
        
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
    int search(vector<int>& nums, int target) {
        int beg=0;
        int end = nums.size()-1;
        int result= -1;
        
        while(beg <= end)
        {
            int mid = beg + (end-beg)/2;

            if(target == nums[mid])
            {
                result = mid;
                break;
            }
            
            if(target> nums[mid])
                beg = mid + 1;
            else
                end = mid - 1;
            
        }
        return result;
    }
};
