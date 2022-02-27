/*
Leetcode

problem- Stone Game VII

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3775/

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

//https://leetcode.com/problems/stone-game-vii/discuss/970268/C%2B%2BPython-O(n-*-n)
typedef pair<int,int> pii;
class Solution {
    int sa=0;
    int dp[1001][1001];
public:
    int game(vector<int>& v,int s,int e,int sum)
    {
        if(s==e)
            return 0;
        if(dp[s][e]>=0)
            return dp[s][e];
        dp[s][e] = max(sum-v[s] - game(v,s+1,e,sum-v[s]), sum-v[e] - game(v,s,e-1,sum-v[e]));
        return dp[s][e];
    }
    int stoneGameVII(vector<int>& s) {
        memset(dp, -1, sizeof(dp));
        sa = accumulate(s.begin(),s.end(),0);
        auto r = game(s,0,s.size()-1,sa);
        return r;
    }
};
