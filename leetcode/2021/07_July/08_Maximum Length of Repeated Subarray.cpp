/*
Leetcode

problem- Maximum Length of Repeated Subarray

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3807/

tags - Medium
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
    int findLength1(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<vector<int>> map(101,vector<int>());
        int result=0;
        for(int i=0;i<nums1.size();++i)
        {
            map[nums1[i]].push_back(i);
        }
        
        for(int i=0;i<nums2.size();++i)
        {
            if(!map[nums2[i]].empty())
            {
                for(auto k:map[nums2[i]])
                {
                    int len = 0;
                    int j = i;
                    if((len2-j<result) || (len1-k<result))
                        break;
                    //cout<<"comp="<<j<<" "<<k<<" ";
                    while(j<len2 && k<len1)
                    {
                        if(!(nums2[j++]==nums1[k++]))
                            break;
                        ++len;
                    }
                    //cout<<" len="<<len<<endl;
                    result = max(result,len);
                }
                
            }
        }
        
        return result;
    }
    //dp - 2D
    int findLength2(vector<int>& nums1, vector<int>& nums2) {
        
        int result=0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        
        for(int i=0;i<len1;++i)
        {
            for(int j=0;j<len2;++j)
            {
                if(nums1[i]==nums2[j])
                {
                    dp[i+1][j+1] = dp[i][j] + 1;
                    result = max(result, dp[i+1][j+1]);
                }
            }
        }
        
        return result;
    }
    // dp - space optimized
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()< nums2.size())
            return findLength(nums2,nums1);
        int result=0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> pre(len2+1,0);
        vector<int> curr(len2+1,0);
        
        for(int i=0;i<len1;++i)
        {
            for(int j=0;j<len2;++j)
            {
                if(nums1[i]==nums2[j])
                {
                    curr[j+1] = pre[j] + 1;
                    result = max(result, curr[j+1]);
                }
            }
            fill(pre.begin(), pre.end(), 0);
            swap(curr,pre);
        }
        
        return result;
    }
};
