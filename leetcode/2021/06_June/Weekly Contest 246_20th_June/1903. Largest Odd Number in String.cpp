/*
Leetcode

problem- 1903. Largest Odd Number in String

Link - https://leetcode.com/problems/largest-odd-number-in-string/

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
    string largestOddNumber(string num) {
        //string result = "";
        int i=num.size()-1;
        for(;i>=0;--i)
        {
            if((num[i]-'0')%2==1)
                break;
        }
        return num.substr(0,i+1);
        
    }
};
