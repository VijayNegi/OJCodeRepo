/*
Leetcode

problem- 1893. Check if All the Integers in a Range Are Covered

Link - https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/

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
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        
        sort(ranges.begin(),ranges.end());
        
        for(int i=0;i<ranges.size();++i)
        {
            if(ranges[i][0] > left)
                return false;
            else if(ranges[i][1]>=left && ranges[i][1]>=right)
                return true;
            else if(ranges[i][1]>=left && ranges[i][1] < right)
                left = ranges[i][1]+1;
        }
        return false;
    }
};
