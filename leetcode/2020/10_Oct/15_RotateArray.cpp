/*
Leetcode
 problem-     Rotate Array

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3496/

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
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        
        k = k%len;
        vector<int> result;
        result.swap(nums);
        
        nums.insert(nums.begin(),result.end()-k, result.end());
        nums.insert(nums.end(),result.begin(), result.end()-k);
        
    }
};
