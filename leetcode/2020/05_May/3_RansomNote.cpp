/*
Leetcode
 problem-   Ransom Note
Link - https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/
        
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
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ransom,mag;
        for (size_t i = 0; i < ransomNote.size(); i++)
        {
            ransom[ransomNote[i]]++;
        }
        for (size_t i = 0; i < magazine.size(); i++)
        {
            mag[magazine[i]]++;
        }
        bool can=false;
        for(auto r:ransom)
        {
            if(mag.count(r.first))
            {
                if(mag[r.first]< r.second)
                    return false;
            }
            else
                return false;
            
        }
        
        return true;
    }
};

