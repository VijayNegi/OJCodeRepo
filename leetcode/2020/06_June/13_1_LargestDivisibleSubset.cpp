/*
Leetcode
 problem-   Largest Divisible Subset

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3359/
        
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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()<=1)
            return nums;
        vector<int> setSize(nums.size(),1);
        vector<int> priv(nums.size(),-1);
        sort(begin(nums),end(nums));
        int MaxSetC(0),MaxSetI(0);
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]%nums[i]==0)
                {
                    if(setSize[i]+1 > setSize[j])
                    {
                        setSize[j] = setSize[i]+1;
                        priv[j] = i;
                    }
                    if(setSize[j]>MaxSetC)
                    {
                        
                        MaxSetC = setSize[j];
                        MaxSetI = j;
                        cout<<"\n maxSetI, count ->"<<MaxSetI<<", "<<MaxSetC;
                    }
                }
            }
        }
        
        vector<int> ret;
        while(MaxSetI>=0)
        {
            ret.push_back(nums[MaxSetI]);
            MaxSetI = priv[MaxSetI];
        }
        return ret;
    }
};
