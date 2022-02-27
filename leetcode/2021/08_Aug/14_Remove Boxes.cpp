/*
Leetcode

problem- Remove Boxes

Link - https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3889/

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

// understanding - https://leetcode.com/problems/remove-boxes/discuss/101310/Java-top-down-and-bottom-up-DP-solutions
// cases - https://leetcode.com/problems/remove-boxes/discuss/1402561/C%2B%2BJavaPython-Top-down-DP-Clear-explanation-with-Picture-Clean-and-Concise
class Solution {
    int removeBoxesSub(vector<int>& boxes,int i,int j,int k,vector<vector<vector<int>>>& dp)
    {
        if(j<i)
            return 0;
        if(dp[i][j][k]>0) return dp[i][j][k];
        
        int i0 = i,k0=k;
        for (; i + 1 <= j && boxes[i + 1] == boxes[i]; i++, k++);
        
        int result = (k+1) * (k+1) + removeBoxesSub(boxes,i+1,j,0,dp);
        for(int m= i+1;m<=j;++m)
        {
            if(boxes[i]==boxes[m])
                result = max(result, removeBoxesSub(boxes,i+1,m-1,0,dp) + removeBoxesSub(boxes,m,j,k+1,dp));
        }
        
        dp[i0][j][k0] = result;
        return result;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n+1,vector(n+1,vector<int>(n+1,0)));
        //vector<vector<vector<int>>> dp(n,vector<int>(n,vector<int>(n,0)));
        return removeBoxesSub(boxes,0,n-1,0,dp);
    }
};
