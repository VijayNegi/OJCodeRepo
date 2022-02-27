/*
Leetcode

problem- Valid Triangle Number

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3815/

tags - similar to 3sum with a twist
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
    int binarySearch(vector<int>& nums, int l,int r,int val)
    {
        while(l<r)
        {
            int mid = (l+r)/2;
            if(nums[mid]>=val)
                r = mid;
            else
                l = mid + 1;
        }
        
        return l;
    }
public:
    //brute force
    int triangleNumber1(vector<int>& nums) {
        int result=0;
        int n= nums.size();
        int sum = 0;
        for(int i=0;i<n-2;++i)
        {
            for(int j=i+1;j< n-1 ;++j)
            {
                for(int k=j+1;k<n;++k)
                {
                    
                    if( (nums[i] + nums[j]>nums[k]) && (nums[k] + nums[j]>nums[i]) && (nums[i] + nums[k]>nums[j]))
                        ++result;
                }
            }
        }
        return result;
    }
    // one less condition, after sorting. still n3
    int triangleNumber2(vector<int>& nums) {
        int result=0;
        int n= nums.size();
        sort(begin(nums),end(nums));
        int sum = 0;
        for(int i=0;i<n-2;++i)
        {
            for(int j=i+1;j< n-1 ;++j)
            {
                for(int k=j+1;k<n;++k)
                {
                    if(nums[i] + nums[j]>nums[k])
                        ++result;
                }
            }
        }
        return result;
    }
    // using binary search. n^2 .logn
    int triangleNumber3(vector<int>& nums) {
        int result=0;
        int n= nums.size();
        sort(begin(nums),end(nums));
        int sum = 0;
        for(int i=0;i<n-2;++i)
        {
            for(int j=i+1;j< n-1 ;++j)
            {
                int sum = nums[i] + nums[j];
                int idx = binarySearch(nums,j+1,n,sum);
                result += idx - j-1;
                
            }
        }
        return result;
    }
    
    // n^2
    int triangleNumber(vector<int>& nums) {
        int result=0;
        int n= nums.size();
        sort(begin(nums),end(nums));
      
        
        for(int i=0;i<n-2;++i)
        {
             if(nums[i]==0)
                 continue;
            int k=i+2;
            for(int j=i+1;(j < n-1);++j)
            {
                while(k < n && nums[k] < nums[i] + nums[j])
                    ++k;
                result += k - j - 1;
            }
        }
        return result;
    }
    
};
