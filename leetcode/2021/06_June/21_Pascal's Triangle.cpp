/*
Leetcode

problem- Pascal's Triangle

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3786/

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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        
        while(result.size()<numRows)
        {
            int sz = result.size();
            result.push_back({1});
            for(int i=1;i<sz;++i)
                result[sz].push_back(result[sz-1][i] + result[sz-1][i-1]);
            result[sz].push_back(1);
        }
        return result;
    }
};
