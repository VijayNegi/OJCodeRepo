/*
Leetcode
 problem-     Remove Covered Intervals

Link - https://leetcode.com/explore/featured/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3483/
        
tags - Vector sort

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

 bool short_by_interval(vector<int> a, vector<int>b)
    {
         if(a[0]<b[0])
             return true;
         else if (a[0]==b[0] && a[1]>b[1])
            return true;
        return false;
    }
class Solution {
public:
   
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), short_by_interval);
        
        // for(auto a: intervals)
        // {
        //     cout<<a[0]<<" "<<a[1]<<endl;
        // }
        int count=1;
        vector<int>& curr = intervals[0];
        
        for(int i=1;i<intervals.size();i++)
        {
            //cout<<curr[0]<<" "<<curr[1]<<endl;
            if(intervals[i][1]>curr[1])
            {
                curr=intervals[i];
                count++;
            }
            
        }
        
        return count;
    }
};
