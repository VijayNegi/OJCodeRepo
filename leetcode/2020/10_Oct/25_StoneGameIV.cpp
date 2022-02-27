/*
Leetcode

 problem-     Stone Game IV

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3507/

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
    
    bool winnerSquareGame(int n) {
        vector<int> dp(max(n,3)+1,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=0;
        dp[3]=1;
        if(n<4)
            return dp[n];
        int lastSq = 1;
        
        for(int i=4;i<=n;++i)
        {
            int j=1;
            for(;j<=i;++j)
            {
                if(j*j>i)
                    break;
                if(dp[i-(j*j)]==0)
                {
                    //cout<<i<<" "<< 1<<endl;
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
