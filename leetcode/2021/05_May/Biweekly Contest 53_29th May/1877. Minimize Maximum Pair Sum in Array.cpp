/*
Leetcode

problem- 1877. Minimize Maximum Pair Sum in Array

Link - https://leetcode.com/contest/biweekly-contest-53/problems/minimize-maximum-pair-sum-in-array/

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
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int result=0;
        for(int i=0; i<n/2;i++)
        {
            result = max(result,nums[i] + nums[n-i-1]);
        }
        return result;
    }
};
