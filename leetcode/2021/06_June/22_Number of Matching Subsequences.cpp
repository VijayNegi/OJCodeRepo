/*
Leetcode

problem- Number of Matching Subsequences

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3788/

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
    int numMatchingSubseq(string s, vector<string>& words) {
        int result=0;
        int len = words.size();
        unordered_map<string, pair<int,int>> wordmap;
        for(const auto& w:words)
        {
            auto it = wordmap.find(w);
            if(it!= wordmap.end())
            {
                (it->second.first)++;
            }
            else
            {
                wordmap[w] = {1,0}; // count , index
            }
        }
        //vector<int> idx(len,0);
        
        for(const auto& c:s)
        {
            for(auto it = wordmap.begin(); it != wordmap.end(); )
            {
                auto& key = it->first;
                auto& idx = it->second.second;
                
                if(key[idx]==c)
                {
                    ++idx;
                    if(idx==key.size())
                    {
                        result+=it->second.first; // count;
                        it= wordmap.erase(it);
                        continue;
                    }
                    
                }
                ++it;
            }
        }
        return result;
        
    }
};
