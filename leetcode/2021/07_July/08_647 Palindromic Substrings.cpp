/*
Leetcode

problem- 647. Palindromic Substrings

Link - https://leetcode.com/problems/palindromic-substrings/

tags - Easy
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
    bool palindrome(const string& s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
            
    }
public:
    int countSubstrings1(string s) {
        int n = s.size();
        int result=n;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(s[i]==s[j] && palindrome(s,i,j))
                {
                    ++result;
                }
            }
        }
        return result;
    }
    int countSubstrings2(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int result=0;
        for(int i=n-1;i>=0;--i)
        {
            for(int j=i;j<n;++j)
            {
                if(s[i]==s[j])
                {
                    if(i==j || j==i+1)
                    {
                        dp[i][j]=1;
                    }
                    else
                    {
                        dp[i][j] = dp[i+1][j-1];
                    }
                    if(dp[i][j])
                        ++result;
                }
            }
        }
        return result;
    }
    //faster , O(1) space
    int countSubstrings(string s) {
        int counter = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                counter++;
            }
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                counter++;
            }
        }
        return counter;
    }
};
