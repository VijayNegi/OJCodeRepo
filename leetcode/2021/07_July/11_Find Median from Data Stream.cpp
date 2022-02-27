/*
Leetcode

problem- Find Median from Data Stream

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3810/

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

class MedianFinder {
    priority_queue<int> high;
    priority_queue<int,vector<int>,greater<int>> low;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(low.size() != high.size())
        {
            low.push(num);
            high.push(low.top());
            low.pop();
        }
        else
        {
            high.push(num);
            low.push(high.top());
            high.pop();
        }
        
    }
    
    double findMedian() {
        double result = 0;
        if(high.size() == low.size())
        {
            //cout<<"h="<<high.top()<<" l="<<low.top()<<endl;
            result = (high.top() + low.top())/2.0;
        }
        else
        {
            //cout<<"l="<<low.top()<<endl;
            result = low.top();
        }

        
        return result;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
