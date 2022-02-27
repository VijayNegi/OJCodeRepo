/*
Leetcode

problem- 20. Valid Parentheses

Link - https://leetcode.com/problems/valid-parentheses/

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
    bool isValid(string s) {
        stack<char> stk;
        
        for(const auto& c:s)
        {
            if(c =='(' || c=='{' || c=='[')
            {
                if(c=='(')
                    stk.push(')');
                else if(c=='{')
                    stk.push('}');
                else
                    stk.push(']');
            }
            else
            {
                if(!stk.empty() && stk.top()==c)
                {
                    stk.pop();
                }
                else
                    return false;
            }
        }
        if(stk.empty())
            return true;
        return false;
    }
};
