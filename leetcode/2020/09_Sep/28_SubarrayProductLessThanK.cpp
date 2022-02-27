/*
Leetcode
 problem-     Subarray Product Less Than K

Link - https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3475/
        
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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int result=0;
        int start=0;
        int product=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=k)
            {
                // reset
                start = i+1;
                product = 1;
                
            }
            else
            {
                product *= nums[i];
                while(product >= k)
                {
                    // remove the elements from the start of subarray
                    product /= nums[start];
                    start++;
                }
                
                result += i-start + 1;
            }
        }
        
        return result;
    }
};
