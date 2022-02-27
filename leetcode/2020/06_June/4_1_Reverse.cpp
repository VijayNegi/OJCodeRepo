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
    void reverseString(vector<char>& s) {
        char temp;
        if(s.size()<2)
            return;
        char* begin = &(s.front());
        char* end = &(s.back());
        while(end>=begin)
        {
            temp = *begin;
            *begin = *end;
            *end = temp;
            //cout<< temp<<" ";
            ++begin;
            --end;
        }
    }
};