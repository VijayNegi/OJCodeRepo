/*
Leetcode

 problem- Find First and Last Position of Element in Sorted Array

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/597/week-5-april-29th-april-30th/3725/

tags - Array

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
    int findLowerEnd(vector<int>& nums,int& target){
        int numsLength = nums.size();
        int start = 0 , end = numsLength - 1;
        int answer = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] == target){
                answer = mid;
                end = mid - 1;
                continue;
            }

            if(nums[mid] > target){
                end = mid - 1;
                continue;
            }

            if(nums[mid] < target){
                start = mid + 1;
                continue;
            }
        }
        return answer;
    }
    
    int findHighEnd(vector<int>& nums,int &target){
        int numsLength = nums.size();
        int start = 0 , end = numsLength - 1;
        int answer = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] == target){
                answer = mid;
                start = mid + 1;
                continue;
            }

            if(nums[mid] > target){
                end = mid - 1;
                continue;
            }

            if(nums[mid] < target){
                start = mid + 1;
                continue;
            }
        }
        return answer;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lowerEnd = findLowerEnd(nums,target);
        int higherEnd = findHighEnd(nums,target);
        return {lowerEnd,higherEnd};
        
        //========================================
        vector<int> result(2,-1);
        
        int len = nums.size();
        if(len==0)
            return result;
        int begin = -0;
        int end = len-1;
        
        while(nums[begin]< nums[end])
        {
            int mid = begin + ((end-begin)/2);
            
            if(nums[mid]> target)
                end = mid-1;
            else if(nums[mid]< target)
                begin = mid+1;
            else
            {
                if(nums[begin]<target)
                    ++begin;
                if(nums[end]>target)
                    --end;
            }
            
        }
        if(nums[begin]==target)
            result[0]=begin,result[1]=end;
        return result;
    }
};
