/*
Leetcode
problem-   Longest Common Subsequence
Link - https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/531/week-4/3311/
        
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
#include <deque>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> dp(len1+1, vector(len2+1, 0));
        //vector<vector<int>> dp;
        // for (size_t i = 0; i < len1+1; i++)
        // {
        //      dp.push_back(vector<int>(len2+1,0));
        // }
        for (int i = 1; i <= len1; i++)
        {
           for (int j = 1; j <= len2; j++)
           {
               if(text1[i-1]==text2[j-1]){
                     //dp[i][j] = min(max(1 + dp[i][j-1] ,1 + dp[i-1][j]),min(i,j));
                     dp[i][j] = dp[i-1][j-1]+1;
               }
               else{
                   dp[i][j] = max( dp[i][j-1] ,dp[i-1][j]);
               }
               //cout<<" "<<dp[i][j];
           }
           //cout<<endl;
           
        }
        
        return dp[len1][len2]; 
    }
    int longestCommonSubsequence1(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        int dp[len1+1][len2+1];
        for (size_t i = 0; i < len1+1; i++)
        {
            dp[i][0]=0;
        }
        for (size_t i = 0; i < len2+1; i++)
        {
            dp[0][i]=0;
        }
        
        for (int i = 1; i <= len1; i++)
        {
           for (int j = 1; j <= len2; j++)
           {
               if(text1[i-1]==text2[j-1]){
                     //dp[i][j] = min(max(1 + dp[i][j-1] ,1 + dp[i-1][j]),min(i,j));
                     dp[i][j] = dp[i-1][j-1]+1;
               }
               else{
                   dp[i][j] = max( dp[i][j-1] ,dp[i-1][j]);
               }
               //cout<<" "<<dp[i][j];
           }
           //cout<<endl;
           
        }
        
        return dp[len1][len2]; 
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
    // //vector<vector<int>> myVec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<int> myVec = {2,3,1,1,4};
    // string str = "((()))*";
    auto ans = obj->longestCommonSubsequence1("abbba","aaa");
     cout << "\n ans -> " << ans;
    
  
    return 0;
}