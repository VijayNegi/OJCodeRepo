/*
Leetcode

 problem-     Champagne Tower

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3508/

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
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<vector<double>> dp(100,vector<double>(100,0));
        dp[0][0] = poured;
        for(int r = 0;r<query_row;++r)
        {
            for(int c = 0; c<=r; ++c)
            {
                if(dp[r][c]>1.0)
                {
                    dp[r+1][c] += (dp[r][c]-1)/2.0;
                    dp[r+1][c+1] += (dp[r][c]-1)/2.0;
                }
            }
        }
        return min(dp[query_row][query_glass],1.0);
    }
};
