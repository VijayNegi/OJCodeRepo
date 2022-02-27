/*
Leetcode

 problem-     Minimum Cost to Move Chips to The Same Position

Link - https://leetcode.com/explore/featured/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3520/

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
    int minCostToMoveChips(vector<int>& position) {
        
        int even=0;
        int odd=0;
        for(const auto& a:position)
        {
            if(a%2)
                ++even;
            else
                ++odd;
        }
        return (even>odd)?odd:even;
    }
};
