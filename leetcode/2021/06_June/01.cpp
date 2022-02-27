/*
Leetcode

problem- To Lower Case

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3754/

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
    string toLowerCase(string s) {
        
        for(auto& c : s)
        {
            if(c>='A' && c<='Z')
            {
                c += 'a' - 'A';
            }
        }
        return s;
    }
};
