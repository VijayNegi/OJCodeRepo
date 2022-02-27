/*
Leetcode

problem- 4Sum

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3816/

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
    int binarySearch(vector<int>& nums, int l,int r,int val)
    {
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]==val)
                return mid;
            if(nums[mid]>val)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return -1;
    }
public:
    vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n= nums.size();
        if(n<4)
            return result;
        set<vector<int>> uniq;
        sort(begin(nums),end(nums));
        for(int i=0;i<n-3;++i)
        {
            for(int j=i+1;j< n-2 ;++j)
            {
                for(int k=j+1;k< n-1 ;++k)
                {
                    int sum = nums[i] + nums[j] +nums[k];
                    int idx = binarySearch(nums,k+1,n-1,target - sum);
                    if(idx>=0)
                        uniq.insert({nums[i],nums[j],nums[k], nums[idx]});
                }
            }
        }
        result.insert(result.end(), begin(uniq),end(uniq));
        return result;
    }
    vector<vector<int>> fourSum2(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n= nums.size();
        if(n<4)
            return result;
        set<vector<int>> uniq;
        sort(begin(nums),end(nums));
        for(int i=0;i<n-3;++i)
        {
            for(int j=i+1;j< n-2 ;++j)
            {
                int l=j+1,h=n-1;
                while(l<h)
                {
                    int sum = nums[i] + nums[j] +nums[l] + nums[h];
                    if(sum==target)
                    {
                        uniq.insert({nums[i],nums[j],nums[l], nums[h]});
                        --h;
                    }
                    else if(sum>target)
                        --h;
                    else
                        ++l;
                        
                }
            }
        }
        result.insert(result.end(), begin(uniq),end(uniq));
        return result;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n= nums.size();
        if(n<4)
            return result;
        //set<vector<int>> uniq;
        sort(begin(nums),end(nums));
        for(int i=0;i<n-3;++i)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j< n-2 ;++j)
            {
                if((j>(i+1)) && nums[j]==nums[j-1])
                    continue;
                int l=j+1,h=n-1;
                while(l<h)
                {
                    int sum = nums[i]+ nums[j]+nums[l]+nums[h];
                    if(sum == target)
                    {

                        result.push_back({nums[i],nums[j],nums[l],nums[h]});
                        --h;
                        ++l;
                        while((l<h) && (nums[l] == nums[l-1])) l++;
                        while((h>l) && (nums[h] == nums[h+1])) h--;

                    }
                    else if(sum>target)
                        --h;
                    else
                        ++l;
                }
            }
        }
       //result.insert(result.end(), begin(uniq),end(uniq));
        return result;
    }
    
};
