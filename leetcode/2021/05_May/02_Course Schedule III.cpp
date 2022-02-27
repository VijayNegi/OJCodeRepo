/*
Leetcode

problem- Course Schedule III

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3729/

tags - max heap, DP
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
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](const std::vector<int>& a, const std::vector<int>& b) {
                                            return a[1] < b[1];
                                            }); // ???? short by end time
        
        int len = courses.size();
        
        vector<vector<int>> dp(len,vector<int>(2,0)); // no of course complete, and minimum end date/ start for next work.
        vector<int> max_heap;
        
        
        for(int i=0;i<len;i++)
        {
            if(courses[i][1]>=courses[i][0])
            {
                if(i==0)
                {
                    dp[i][0] = 1; // one course can be completed
                    dp[i][1] = courses[i][0];
                    max_heap.push_back(courses[i][0]);
                }
                else
                {
                    if((dp[i-1][1] + courses[i][0]) <= courses[i][1]) // course can be completed
                    {
                        dp[i][0]= dp[i-1][0]+1;
                        dp[i][1]= dp[i-1][1] + courses[i][0];
                        max_heap.push_back(courses[i][0]);
                        push_heap(max_heap.begin(),max_heap.end());
                    }
                    else if(max_heap.front() > courses[i][0]) // improve finish time
                    {
                        dp[i][0]= dp[i-1][0]; // same
                        dp[i][1]= dp[i-1][1] + courses[i][0] - max_heap.front();
                        
                        pop_heap(max_heap.begin(),max_heap.end());
                        max_heap[max_heap.size()-1] = courses[i][0];
                        push_heap(max_heap.begin(),max_heap.end());
                    }
                    else // keep previous timing
                    {
                        dp[i][0]= dp[i-1][0];
                        dp[i][1]= dp[i-1][1];
                    }
                   
                }
            }
        }
        
        return dp[len-1][0];
        
    }
};
