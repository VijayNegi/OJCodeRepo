
/*
Leetcode

problem- Max Consecutive Ones III

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/607/week-5-june-29th-june-30th/3796/

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

//https://leetcode.com/problems/max-consecutive-ones-iii/discuss/247564/JavaC%2B%2BPython-Sliding-Window
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0;
        int end=0;
        int result = 0;
        int zeros=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==0)
            {
                
                if(zeros==k)
                {
                    while(start<=end && nums[start++] == 1);
                }
                else
                    ++zeros;
            }
            ++end;
            result = max(result,end-start);
            //cout<<i<<" "<<result<<" ="<<start<<"-"<<end<<endl;
        }
        return result;
    }
    int longestOnes1(vector<int>& nums, int k) {
        int start=0;
        int end=0;
        int result = 0;
        vector<int> vec(k,-1);
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq(vec.begin(), vec.end());
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==0)
            {
                if(!pq.empty())
                {
                    nums[i]=1;
                    int idx = pq.top();
                    //cout<<"stack top="<<idx<<endl;
                    if(idx>=0)
                    {
                        nums[idx]=0;
                        start = idx;
                    }
                    pq.pop();
                    pq.push(i);
                }
                else
                    start = i;
                
                while(start<=end && nums[start]==0 )
                    ++start;
                ++end;
                
            }
            else
                ++end;
            result = max(result,end-start);
            //cout<<i<<" "<<result<<" ="<<start<<"-"<<end<<endl;
        }
        return result;
    }
};
