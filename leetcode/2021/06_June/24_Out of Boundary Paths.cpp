/*
Leetcode

problem- Out of Boundary Paths

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3790/

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
    //int result;
    int mod;
    vector<vector<vector<int>>> dp;
    int dfs(int m,int n, int maxMove,int row,int col )
    {
        //cout<<row<<" "<<col<<" "<<maxMove<<endl;
        auto isOutOfGrid = [&](int r, int c){ return (r<0 || r>=m || c<0 || c>=n); };
        if(isOutOfGrid(row,col))
        {
            return 1;
        }
        else if(maxMove==0)
            return 0;
        else if(dp[row][col][maxMove]>=0)
            return dp[row][col][maxMove];
        
        
        
        auto CanReachBorder = [&](int r,int c){ return (r-maxMove-1 <0 || r+maxMove-1>=m || c-maxMove-1<0 || c+maxMove-1>=n);  };
        
        int result=0;
        if(CanReachBorder(row+1,col))
            result = ( result + dfs(m,n,maxMove-1,row+1,col) ) % mod;
        if(CanReachBorder(row-1,col))
            result = ( result + dfs(m,n,maxMove-1,row-1,col) ) % mod;
        if(CanReachBorder(row,col+1))
            result = ( result + dfs(m,n,maxMove-1,row,col+1) ) % mod;
        if(CanReachBorder(row,col-1))
            result = ( result + dfs(m,n,maxMove-1,row,col-1) ) % mod;
        dp[row][col][maxMove] = result ;//% mod;
        return dp[row][col][maxMove];
    }
public:
    int findPaths1(int m, int n, int maxMove, int startRow, int startColumn) {
        int result=0;
        mod = 1e9+7;
        dp = vector(m,vector(n,vector(maxMove+1,-1)));
        //dp = vector<m,vector<n,vector<maxMove,-1>>>;
        result = dfs(m,n,maxMove,startRow,startColumn);
        return result;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (!maxMove) return 0;
        vector<vector<int>> dpCurr(m+2, vector<int>(n+2)),
            dpLast(m+2, vector<int>(n+2));
        for (int i = 1; i <= m; i++)
            dpCurr[i][1]++, dpCurr[i][n]++;
        for (int j = 1; j <= n; j++)
            dpCurr[1][j]++, dpCurr[m][j]++;
        int ans = dpCurr[startRow+1][startColumn+1];
        for (int d = 1; d < maxMove; d++) {
            dpCurr.swap(dpLast);
            for (int i = 1; i <= m; i++)
                for (int j = 1; j <= n; j++)
                    dpCurr[i][j] = (int)(((long)dpLast[i-1][j] + dpLast[i+1][j] + dpLast[i][j-1] +          dpLast[i][j+1]) % 1000000007L);
            ans = (ans + dpCurr[startRow+1][startColumn+1]) % 1000000007;
        }
        return ans;
    }
};
