/*
Leetcode

problem- 1936. Add Minimum Number of Rungs

Link - https://leetcode.com/problems/add-minimum-number-of-rungs/

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
    int addRungs(vector<int>& rungs, int dist) {
        int result = 0;
        int n = rungs.size();
        int ch = 0;
        for(int i=0;i<n;++i)
        {
            if(rungs[i] - ch <= dist)
                ch = rungs[i];
            else
            {
                int add = (rungs[i]-ch-1)/dist;
                result += add;
                ch = rungs[i];
            }
        }
        return result;
    }
};
