/*
Leetcode

problem- Evaluate Reverse Polish Notation

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3755/

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
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for(const auto s:tokens)
        {
            if(s!="+" && s!="-" && s!="/" && s!="*")
                stk.push(std::stoi(s));
            else
            {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                switch(s[0])
                {
                    case '+': stk.push(a+b);
                        break;
                    case '-': stk.push(b-a);
                        break;
                    case '*': stk.push(a*b);
                        break;
                    case '/':stk.push(b/a);
                        break;
                }
            }
        }
        return stk.top();
    }
};
