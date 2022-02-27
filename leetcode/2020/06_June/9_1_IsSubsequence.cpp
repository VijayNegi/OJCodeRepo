/*
Leetcode
 problem-   Is Subsequence
 
Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3355/
        
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
    bool isSubsequence(string s, string t) {
        if(s.size()> t.size())
            return false;
        if(s.size()<1)
            return true;
        
        int i(0),j(0);
        while(true)
        {
            if(i>=s.size() || j>= t.size())
                break;
            else if(s[i]==t[j])
            {
                i++;j++;
            }
            else
                j++;
        }
        
        if(i>= s.size())
            return true;
        
        return false;
    }
};
