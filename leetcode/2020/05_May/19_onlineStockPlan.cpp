/*
Leetcode
problem-    Online Stock Span
Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3334/
        
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
#include <map>
#include <list>
#include <utility>
#include <deque>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;


class StockSpanner {
public:
    int size;
    vector<int> input;
    vector<int> dp;
    StockSpanner() {
        size=-1;
    }
    
    int next(int price) {
        input.push_back(price);
        size++;
        int ans=1;
        if(size==0)
            dp.push_back(1);
        else
        {
           int pos = size-1; 
            while(true)
            {
                if(input[pos] > input[size])
                {
                    ans = size - pos;
                    dp.push_back(ans);
                    break;
                }
                else
                {
                    pos = pos - dp[pos];
                    if(pos<0)
                    {
                        ans = size+1;
                        dp.push_back(ans);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

