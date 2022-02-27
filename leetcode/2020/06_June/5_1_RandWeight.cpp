/*
Leetcode
problem-   Reverse String
Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3350/
        
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
    vector<int> sums;
    Solution(vector<int>& w) {
        sums.reserve(w.size());
        int temp=0;
        for(int i=0;i<w.size();i++)
        {
            temp+=w[i];
            sums.push_back(temp);
            //cout<<" ->"<<temp;
        }
    }
    
    int pickIndex() {
        int r = rand()%(sums.back());
        //cout<<"\n r="<<r<< " ";
        auto it=upper_bound(sums.begin(),sums.end(),r);
        
        int ans = 0;
        for(int i = 0 ;i<sums.size();i++)
        {
            if(r< sums[i])
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */