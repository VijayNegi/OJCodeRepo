/*
Leetcode
 problem-   Find the Difference

Link - https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3471/
        
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
    char findTheDifference(string s, string t) {
        int smap[26]={0};
        int tmap[26]={0};
        for(int i=0;i< s.size();i++)
        {
            ++smap[s[i]- 'a'];
            ++tmap[t[i]- 'a'];
        }
        ++tmap[t[t.size()-1]- 'a'];
        char ans = 'a';
        for(int i=0;i < 26 ; i++)
        {
            if(tmap[i]- smap[i]>0)
            {
                ans = 'a'+ i;
                break;
            }
        }
        return ans;
    }
};
