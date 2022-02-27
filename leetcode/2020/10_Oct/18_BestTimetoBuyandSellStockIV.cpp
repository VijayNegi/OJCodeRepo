/*
Leetcode

 problem-     Best Time to Buy and Sell Stock IV

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3499/

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
    int maxProfit(vector<int>& p, int res = 0) {
      for (int i = 1; i < p.size(); ++i) res += max(0, p[i] - p[i - 1]);
      return res;
    }
    int maxProfit(int k, vector<int>& prices) {
      if (k >= prices.size() / 2) return maxProfit(prices);
      vector<int> buys(k + 1, INT_MIN), sells(k + 1, 0);
      for (auto p : prices)
      {
        //cout<<endl<<"input- "<<p<<endl;
          
        for (auto i = 1; i <= k; ++i) {
            
          buys[i] = max(buys[i], sells[i - 1] - p);
          sells[i] = max(sells[i], buys[i] + p);
          //cout<<buys[i]<<" "<<sells[i]<<" ";
        }
      }
      return sells[k];
    }
};
