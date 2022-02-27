/*
Leetcode

problem- 1876. Substrings of Size Three with Distinct Characters

Link - https://leetcode.com/contest/biweekly-contest-53/problems/substrings-of-size-three-with-distinct-characters/

tags - Easy
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
    int countGoodSubstrings(string s) {
        int map[26] = {0};
        int distinct = 0;
        int result = 0;
        for(int i = 0;i<s.size();i++)
        {
            int c = s[i] - 'a';
            if(map[c]==0)
            {
                ++map[c];
                distinct++;
            }
            else
            {
                ++map[c];
            }
            if(i>2)
            {
                c = s[i-3] - 'a';
                if(map[c]==1)
                {
                    --map[c];
                    --distinct;
                }
                else
                {
                    --map[c];
                }
            }
            if(distinct == 3)
                ++result;
            
        }
        return result;
    }
    
};
