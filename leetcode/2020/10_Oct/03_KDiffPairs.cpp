/*
Leetcode
 problem-     K-diff Pairs in an Array

Link - https://leetcode.com/submissions/detail/404004144/?from=/explore/featured/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3482/
        
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
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int , int> _map;
        int result=0;
        for(auto num: nums)
        {
            _map[num]++;
        }
        
        for(auto entry: _map)
        {
            
            if(_map.count(entry.first + k))
            {
                if(k==0)
                    result += min(1,_map[entry.first]-1);
                else
                    result++;
            }
        }

        return result;
    }
};
