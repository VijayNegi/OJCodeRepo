/*
Leetcode
problem-   Two City Scheduling
Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3349/
        
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
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> sol(costs.size());
        int sum=0;
        for(int i=0;i<costs.size();i++)
        {
            sum+=costs[i][0];
            sol[i]=(costs[i][0]-costs[i][1]);
        }
        sort(sol.begin(),sol.end(),greater());
        for(int i=0;i<((sol.size())/2);i++)
        {
            sum-=sol[i];
        }
        return sum;
    }
};
