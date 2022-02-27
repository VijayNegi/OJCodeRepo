/*
Leetcode

 problem-     Repeated DNA Sequences

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3498/

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
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> m;
        vector<string> result;
        unsigned int curr=0;
        for(int i = 0; i< s.size();i++)
        {
            curr = (curr<<3 & 0x3FFFFFFF) | s[i] & 7;
            if(m[curr]++ == 1)
                result.push_back(s.substr(i-9,10));
        }
        return result;
    }
    
};
