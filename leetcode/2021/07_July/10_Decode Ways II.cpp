/*
Leetcode

problem- Decode Ways II

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3809/

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

//https://leetcode.com/problems/decode-ways-ii/discuss/105274/Python-Straightforward-with-Explanation
class Solution {
public:
    int numDecodings(string s) {
        long e0=1,e1=0,e2=0;
        const int m = 1e9 + 7;
        for(const auto& c: s)
        {
            long f0,f1,f2;
            if(c=='*')
            {
                f0 = 9 * e0  + 9*e1 + 6*e2;
                f1 = e0;
                f2 = e0;
            }
            else
            {
                f0 = (c > '0') * e0 + e1 + (c  <= '6') * e2;
                f1 = (c=='1') * e0;
                f2 = (c=='2') * e0;
            }
            e0 = (f0%m) ,e1 = f1, e2 = f2;
        }
        return e0;
    }
};
