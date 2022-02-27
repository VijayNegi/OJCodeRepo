/*
Leetcode

problem- Maximum Erasure Value

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3758/

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
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> sum(nums.size()+1,0);
        unordered_map<int,int> hmap;
        int prePos=-1;
        int result=0;
        for(int i=0;i<nums.size();++i)
        {
            sum[i+1] = sum[i]+nums[i];
            
            auto pos = hmap.find(nums[i]);
            if (pos != hmap.end())
            {
                if(pos->second > prePos)
                {
                    //cout<<"->"<<prePos<<" - "<<i<<endl;
                    result = max(result, sum[i] - sum[prePos +1 ]);
                    for(int j=prePos+1;j<pos->second;++j)
                    {
                        hmap.erase(nums[j]);
                    }
                    prePos = pos->second;
 
                }
            }
            
            hmap[nums[i]] = i;
        }
        //cout<<"E->"<<prePos<<" - "<<nums.size()-1<<endl;
        result = max(result, sum[nums.size()] - sum[prePos + 1 ]);
        return result;
    }
};
