/*
Leetcode

problem- Maximum Product of Word Lengths

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3757/

tags - Medium
 
Comment - This problem will be extremly hard to optimize if multiple is not limited to two string.
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
    int wordmask(string& word)
    {
        int mask=0;
        for(auto& c:word)
        {
            mask |= 1<<(c-'a');
        }
        return mask;
    }
public:
    int maxProduct(vector<string>& words) {
        
        map<int,int> msk;
     
        for(int i=0;i<words.size();i++)
        {
            int mask = wordmask(words[i]);
            msk[mask] = max(msk[mask], static_cast<int>(words[i].size()));
        }
        int result=0;
        for(auto& a:msk)
        {
            for(auto& b:msk)
            {
                if(!(a.first & b.first))
                {
                    result = max(result,a.second* b.second);
                }
                
            }
        }
        return result;
    }
};
