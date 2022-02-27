/*
Leetcode

problem- Generate Parentheses

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3781/

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
    void dfs(vector<string> &r,string &s, int open,int close,int pos)
    {
        if(open==0 && close==0)
        {
            r.push_back(s);
            return;
        }
        
        if(open)
        {
            s[pos] = '(';
            dfs(r,s,open-1,close,pos+1);
        }
        if(close && open<close)
        {
            s[pos] = ')';
            dfs(r,s,open,close-1,pos+1);
        }
        
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        string s(n*2,' ');
        
        dfs(result,s,n,n,0);
        
        return result;
        
    }
};
