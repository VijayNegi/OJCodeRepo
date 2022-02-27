/*
Leetcode
 problem-   Perfect Squares

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3373/
        
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
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        int i=0,sqr=0;
        sqr = i*i;
        while(sqr<=n)
        {
            dp[sqr]=1;
            ++i;
            sqr = i*i;
        }
        for(int i=2;i<=n;++i)
        {
            if(dp[i]==1)
                continue;
            dp[i]= dp[i-1] +1;
            for(int j=2;j<i;j++)
            {
                if(i-j*j>0)
                {
                    dp[i]= min(dp[i],dp[i-j*j] + 1);
                }
                else
                    break;
            }
        }
        
        return dp[n];
    }
};
