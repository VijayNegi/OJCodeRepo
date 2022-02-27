/*
Leetcode

 problem- Unique Paths II

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3723/

tags - DP

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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int result=0;
        int rows = obstacleGrid.size();
        int cols=0;
        if(rows)
            cols = obstacleGrid[0].size();
        if(!rows && !cols)
            return result;
        
        vector<int> dp(cols,0);
        dp[0]=1;
        
        for(int row=0;row<rows;row++)
        {
            for(int col=0;col<cols;col++)
            {
                if(col)
                    dp[col] += dp[col-1];
                if(obstacleGrid[row][col]==1)
                {
                    dp[col]=0;
                }
            }
        }
        
        result = dp[cols-1];
        return result;
        
    }
};
