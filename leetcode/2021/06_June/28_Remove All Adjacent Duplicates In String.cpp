/*
Leetcode

problem- Remove All Adjacent Duplicates In String

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3794/

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
    string removeDuplicates(string s) {
        int k=0;
        
        for(int i=1;i<s.size();++i)
        {
            if(k>=0 && s[k]==s[i])
                --k;
            else
            {
                s[++k]= s[i];
            }
        }
        
        return s.substr(0,k+1);
    }
};
