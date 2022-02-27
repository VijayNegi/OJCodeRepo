/*
Leetcode

problem- Custom Sort String

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3813/

tags - Medium
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
    string customSortString1(string order, string str) {
        vector<int> map(26,0);
        
        for(const auto& c:str)
        {
            map[c-'a']++;
        }
        string result;
        for(const auto& c:order)
        {
            if(map[c-'a'])
            {
                result.append(map[c-'a'], c);
                map[c-'a'] = 0;
            }
        }
        
        for(int idx=0;idx<26;++idx)
        {
            if(map[idx])
            {
                result.append(map[idx], 'a'+idx);
            }
        }
        return result;
    }
    // Thinking in terms of existing algorithmalgorithm
    string customSortString(string order, string str) {
      vector<int> order_list(26, 26);
      int idx = 0;
      for(auto c : order){
        order_list[c - 'a'] = idx;
        idx ++;
      }
      
      sort(str.begin(), str.end(), [&order_list](char a, char b){
        return order_list[a - 'a'] < order_list[b - 'a'];
      });
        
      return str;
    }
};
