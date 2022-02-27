/*
Leetcode
 problem-     Teemo Attacking

Link - https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3473/
        
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
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int start=0;
        int result=0;
        if(timeSeries.size()<1)
            return 0;
        start = timeSeries[0]+duration;
        result = duration;
        
        for(int i=1;i<timeSeries.size();i++)
        {
            // int temp = timeSeries[i] - start;
            if(timeSeries[i]>start)
            {
                result+=duration;
                start = timeSeries[i] + duration;
            }
            else
            {
                result +=timeSeries[i]+duration - start;
                start = timeSeries[i] + duration;
            }
        }
        return result;
    }
};
