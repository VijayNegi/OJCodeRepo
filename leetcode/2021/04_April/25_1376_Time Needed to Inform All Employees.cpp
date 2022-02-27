/*
Leetcode

 problem- 1376. Time Needed to Inform All Employees

Link - https://leetcode.com/problems/time-needed-to-inform-all-employees/

tags - Tree

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
    int ans;
    vector<vector<int>> orgtree;
    vector<int> informTime;
    vector<int> dp;
    int dfs(int i)
    {
        int time=0;
        for(const auto& child:orgtree[i])
        {
            if(dp[i]==-1)
                time = max(time, dfs(child));
            else
                time = max(time, dp[i]);
        }
        time += informTime[i];
        dp[i]= time;
        return time;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& _informTime) {
        orgtree= vector<vector<int>>(n);
        informTime = _informTime;
        dp = vector<int>(n,-1);
        for(int i=0;i<n;i++)
        {
            if(i!=headID)
                orgtree[manager[i]].push_back(i);
        }
        ans = dfs(headID);
        
        return ans;
        
    }
};
