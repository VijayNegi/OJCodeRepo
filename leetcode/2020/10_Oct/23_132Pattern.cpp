/*
Leetcode

 problem-     132 Pattern

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3505/

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
    bool find132pattern2(vector<int>& nums) {  // looked the different solution
        stack<int> s;
        int prev = INT_MIN;
        
        for (auto it = nums.rbegin(); it != nums.rend(); it++) {
            while (!s.empty() && s.top() < *it) {
                if (prev > s.top())
                    return true;
                prev = s.top();
                s.pop();
            }
            
            s.push(*it);
        }
        
        return !s.empty() && prev > s.top();
    }
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if(len<3)
            return false;
        
        vector<vector<int>> minmax;
        int min,max;
        min = max = nums[0];
        minmax.push_back({nums[0],nums[0]});
        
        for(int i=1;i<len;++i)
        {
            for(const auto& a: minmax)
            {
                //cout<<" "<<a[1]<<" "<<a[0]<<" "<<nums[i]<<endl;
                if(nums[i]<a[1] && nums[i] > a[0])
                    return true;
            }
            if(nums[i]< minmax.back()[0])
            {

                if(minmax.back()[0] != minmax.back()[1])
                    minmax.push_back({nums[i],nums[i]});
                else
                {
                    minmax[minmax.size()-1][0] = nums[i];
                    minmax[minmax.size()-1][1] = nums[i];
                }
            }
            else if(nums[i]>minmax.back()[1])
            {

                minmax[minmax.size()-1][1] = nums[i];
            }
        }
        return false;
        
    }
};
