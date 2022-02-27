/*
Leetcode
 problem-   Plus One

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3382/
        
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
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size()<1)
        {
            digits.push_back(1);
            return digits;
        }
        
        bool append(false);
        for(int i=digits.size()-1;i>=0;--i)
        {
            if(digits[i]<9)
            {
                ++digits[i];
                break;
            }
            else
            {
                digits[i]=0;
            }
        }
      
        if(digits[0]==0)
        {
            digits.push_back(0);
            digits[0]=1;
        }
        
        return digits;
    }
};
