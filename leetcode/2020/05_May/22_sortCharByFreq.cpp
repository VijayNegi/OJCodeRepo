/*
Leetcode
 problem-    Sort Characters By Frequency
Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3337/
        
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


class Solution {
public:
    struct freq{    char c;
        int count;
    };
    string frequencySort(string s) {
        vector<freq> vecf;
        vecf.reserve(26);
        string ans;
        // for(int i=0;i < 26;i++)
        // {
        //     vecf.push_back({static_cast<char>('a'+i),0});
        // }
        map<char,int> _map;
        for(auto ch : s)
        {
            auto search = _map.find(ch);
            if (search != _map.end())
            {
                vecf[search->second].count++;
            }
            else
            {
                int loc = vecf.size();
                _map[ch]= loc;
                vecf.push_back({ch,1});
            }
            
            
        }
        sort(vecf.begin(), vecf.end(), [](const freq& lhs, const freq& rhs) {
            return lhs.count > rhs.count;
        });
        for(auto it : vecf)
        {
            //for(int i=0;i<it.count;i++)
            ans.append(it.count,it.c);
        }
        return ans;
        
    }
};
