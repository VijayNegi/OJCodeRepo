/*
Leetcode
problem-  Min stack
tags -

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <stack>
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    std::stack<int> _Data;
    std::stack<int> _Min;
    MinStack() {
        
    }
    
    void push(int x) {
        _Data.push(x);
        if(!_Min.empty())
        {
            if(_Min.top()>=_Data.top())
                _Min.push(_Data.top());
        }
        else
        {
            _Min.push(_Data.top());
        }
        
    }
    
    void pop() {
        if(!_Data.empty())
        {
            if(_Data.top()==_Min.top())
            {
                _Data.pop();
                _Min.pop();
            }
            else
                _Data.pop();
        }
    }
    
    int top() {
        if(!_Data.empty())
            return _Data.top();
        return 0;
    }
    
    int getMin() {
        if(!_Min.empty())
            return _Min.top();
        return 0;
    }
};


int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // disable buffering on stdout completely
    setbuf(stdout, NULL);
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
   
#endif
#if 0
    int TestCases = 4;
    scanf("%d",&TestCases);
    ulong T=1;

    while(TestCases--/*true*/)
    {
        if(!SolveCase(T))
            break;
        T++;
    }
#endif
    MinStack* obj = new MinStack();
    obj->push(2);
    obj->push(0);
    obj->push(3);
    obj->push(0);
    cout<<obj->getMin()<<" - ";
    obj->pop();
    cout<<obj->getMin()<<" - ";
    obj->pop();
    cout<<obj->getMin()<<" - ";
    obj->pop();
    cout<<obj->getMin()<<" - ";
    return 0;
}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */