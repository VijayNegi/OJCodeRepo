/*
Leetcode

problem- 1905. Count Sub Islands

Link - https://leetcode.com/problems/count-sub-islands/

// Note - keep in mind 2nd operand of && will not execute if first is false !!!!! i.e.
//         result =  result && dfs(grid1,grid2,r,c-1,rows,cols);
//  Code like above will give you headache.

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
    bool dfs1(vector<vector<int>>& grid1,vector<vector<int>>& grid2, int r, int c, int rows, int cols)
    {
        //cout<<"dfs - "<<r<<" "<<c<<endl;
        auto valid = [&](int r1,int c1){ return ((r1>=0 && r1<rows) && (c1>=0 && c1<cols))? true:false;};
        grid2[r][c] = 0;// visited;
        bool result = true;
        if(valid(r,c-1) && grid2[r][c-1]==1)
            result = dfs(grid1,grid2,r,c-1,rows,cols) && result;
        if(valid(r-1,c) && grid2[r-1][c]==1)
            result = dfs(grid1,grid2,r-1,c,rows,cols)  && result;
        if(valid(r,c+1) && grid2[r][c+1]==1)
            result = dfs(grid1,grid2,r,c+1,rows,cols) && result;
        if(valid(r+1,c) && grid2[r+1][c]==1)
            result = dfs(grid1,grid2,r+1,c,rows,cols) && result;
        if(!grid1[r][c])
             result=false;
        return result;
    }
    
    bool dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2, int r, int c, int rows, int cols)
    {
        auto valid = [&](int r1,int c1){ return ((r1>=0 && r1<rows) && (c1>=0 && c1<cols))? true:false;};
        if(!valid(r,c) || grid2[r][c]==0)
            return true;
        grid2[r][c] = 0;// visited;
        bool result = true;

        result &= dfs(grid1,grid2,r,c-1,rows,cols);
        result &= dfs(grid1,grid2,r-1,c,rows,cols);
        result &= dfs(grid1,grid2,r,c+1,rows,cols);
        result &= dfs(grid1,grid2,r+1,c,rows,cols);
        result &= grid1[r][c];

        return result;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int result=0;
        int rows = grid2.size();
        int cols = grid2[0].size();
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid2[i][j]==1) // visit
                {
                    if(dfs(grid1,grid2,i,j,rows,cols))
                        ++result;
                }
            }
        }
        return result;
    }
};
