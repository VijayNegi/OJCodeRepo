/*
Leetcode
problem-   Minimum Path Sum
Link - https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3303/
        https://leetcode.com/problems/minimum-path-sum/
tags - Array , dynamic programming

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
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;

class Solution
{
public:
    int gRows = 0;
    int gCols = 0;
    vector<vector<int>>visited;
    int getsum(vector<vector<int>>& grid, int i,int j){
        int down = INT_MAX,right = INT_MAX;
        if((i == (gRows-1) )&& (j==(gCols-1)))
            return grid[i][j];
        if((i <= (gRows-1) )&& (j<=(gCols-1)) && visited[i][j]>=0)
            return visited[i][j];

        // if(i+1<gRows)
        //     down = (visited[i+1][j]>0)?visited[i+1][j]:visited[i+1][j]=getsum(grid,i+1,j);
        // if(j+1<gCols)
        //     right = (visited[i][j+1]>0)?visited[i][j+1]:visited[i][j+1]=getsum(grid,i,j+1);
        if(i+1<gRows)
            down = getsum(grid,i+1,j);
        if(j+1<gCols)
            right =getsum(grid,i,j+1);
        
        return visited[i][j] = grid[i][j] + min(down,right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        gRows = grid.size();
        if(gRows)
            gCols = grid[0].size();
        else
            return 0;
        visited.clear();
        for (int i = 0; i < gRows; i++)
        {
            visited.push_back(vector<int>(gCols,-1));
        }
        
        
        return getsum(grid,0,0);        
    }
};

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // disable buffering on stdout completely
    setbuf(stdout, NULL);
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

#endif
    Solution *obj = new Solution();
    vector<vector<int>> myVec = {{1,3,1},{1,5,1},{4,2,1}};
    string str = "((()))*";
    auto ans = obj->minPathSum(myVec);
    cout << "\n ans -> " << ans;

    return 0;
}