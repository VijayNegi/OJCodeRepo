/*
Leetcode

problem- K Inverse Pairs Array

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3784/

tags - Hard
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

// my explanation https://leetcode.com/problems/k-inverse-pairs-array/discuss/1283469/C%2B%2B-with-easy-explanation.
class Solution {
public:
    int kInversePairs(int n, int k) {
      
        int mod = 1e9+7;
        vector<vector<long>> dp(n+1,vector<long>(k+1,0));
        dp[1][0] = 1;
        for(int i=2; i<=n;++i)
        {
               int len = min(k,(i*(i-1)/2));
               for(int j=0;j<=len;++j)
               {
                   if(j==0)
                       dp[i][j]=1;
                   else
                   {
                       if(j>=i)
                            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-i];
                       else
                           dp[i][j] = dp[i][j-1] + dp[i-1][j];
                   }
                   dp[i][j] = (dp[i][j]+mod)%mod;
               }
        }
        return dp[n][k];
    }
};
