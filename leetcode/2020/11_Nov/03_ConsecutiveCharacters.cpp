/*
Leetcode

 problem-     Consecutive Characters

Link - https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3518/

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
    int maxPower(string s) {
        char p = '0';
        int count=0;
        int maxCount=0;
        for(auto a: s)
        {
            if(a!=p)
            {
                maxCount = (count>maxCount)?count:maxCount;
                count=0;
                p=a;
            }
            ++count;
        }
        maxCount = (count>maxCount)?count:maxCount;
        return maxCount;
    }
};
