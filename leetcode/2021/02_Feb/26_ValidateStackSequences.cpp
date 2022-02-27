/*
Leetcode

 problem- Validate Stack Sequences

Link - https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3653/

tags - Stack

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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int stack_size = pushed.size();
        if(stack_size<3)
            return true;
        stack<int> stk;
        int pushed_idx = 0;
        int popped_idx = 0;
        bool result = false;
        
        while(popped_idx < stack_size)
        {
            if(!stk.empty() && (stk.top()==popped[popped_idx]))
            {
                stk.pop();
                ++popped_idx;
            }
            else if(pushed_idx < stack_size)
            {
                stk.push(pushed[pushed_idx++]);
            }
            else
            {
                break;
            }
        }
        if((pushed_idx==stack_size) && (popped_idx==stack_size))
        {
                result = true;
        }
            
        return result;
    }
};


/* others solution 
 class Solution {
 public:
     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
         stack<int> stack;
         int i = 0;
         for (auto x : pushed) {
             stack.push(x);
             while (stack.size() && stack.top() == popped[i]) {
                 stack.pop();
                 i++;
             }
         }
         return stack.size() == 0;
     }
 };
*/
