/*
Leetcode

 problem-     Summary Ranges

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3510/

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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.empty())
            return result;
        if(nums.size() == 1)
        {
            result.push_back(to_string(nums[0]));
            return result;
        }
        int len = 0;
        for(int i=0;i<nums.size();++i)
        {
            if(len==0)
                ++len;
            else if(nums[i-1] == (nums[i]-1))
                ++len;
            else
            {
                if(len==1)
                {
                    string s = to_string(nums[i-1]);
                    result.push_back(s);
                }
                else
                {
                    string s = to_string(nums[i-len])+"->"+to_string(nums[i-1]);
                    result.push_back(s);
                }
                len=1;
            }
                
        }
        if(len==1)
        {
            string s = to_string(nums[nums.size()-1]);
            result.push_back(s);
        }
        else if(len > 1)
        {
            string s = to_string(nums[nums.size()-len])+"->"+to_string(nums[nums.size()-1]);
            result.push_back(s);
        }
        
          return result;
    }
};
