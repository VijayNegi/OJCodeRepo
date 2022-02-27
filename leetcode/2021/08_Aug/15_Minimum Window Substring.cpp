/*
Leetcode

problem- Minimum Window Substring

Link - https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3891/
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

// https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
class Solution {
public:
    string minWindow(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        int dict[128]={0};
        //fill_n(dict,128,0);
        
        for(int i=0;i<tlen;++i)
            ++dict[t[i]];
        
        int start=0,end=0,begin,len = INT_MAX;
        
        while(end<slen)
        {
            if(dict[s[end]]>0)
                --tlen;
            --dict[s[end]]; // values not in t will become negative
            ++end;
            while(tlen==0) // found a match
            {
                if(len>end-start)
                {
                    begin = start;
                    len = end-start;
                }
                
                ++dict[s[start]];
                if(dict[s[start]]>0) // if it was in t it will become postive
                    ++tlen;
                ++start;
            }
        }
        
        string result;
        if(len<=slen)
            result = s.substr(begin,len);
        return result;
    }
};
