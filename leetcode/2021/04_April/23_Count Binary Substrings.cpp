/*
Leetcode

 problem- Count Binary Substrings

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3718/

tags - Strings

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
    int countBinarySubstrings(string s) {
        int preCount=0,currCount=1;
        int result=0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i-1]!=s[i])
            {
                result+=min(currCount,preCount);;
                preCount = currCount;
                currCount = 1;
            }
            else
                currCount++;
        }
        // handle last strings
        return result + min(currCount,preCount);
    }
};
