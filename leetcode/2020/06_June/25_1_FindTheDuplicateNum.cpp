/*
Leetcode
 problem-   Find the Duplicate Number

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3371/
        
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
    int findDuplicate(vector<int>& nums) {
        int slow(0),fast(0);
        
        while(true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast)
                break;
        }
        
        slow = 0;
        while(true)
        {
            slow = nums[slow];
            fast = nums[fast];
            if(slow==fast)
                break;
        }
        return slow;
    }
};
