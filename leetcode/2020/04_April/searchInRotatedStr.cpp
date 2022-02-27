/*
Leetcode
problem-   Search in Rotated Sorted Array
Link - https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3304/
        https://leetcode.com/problems/search-in-rotated-sorted-array/
tags - Array , Binary search

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
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        int beg = 0;
        int end = nums.size() - 1;
        int mid;
        int midVal;
        while (beg <= end)
        {

            mid = (beg + end + 1) / 2.0;
            midVal = nums[mid];
            if (midVal == target)
                return mid;
            else if (beg >= end)
                break;

            else if(midVal<nums[beg]){
                if (target <= nums[end] and target > midVal){
                    
                    beg = mid +1;
                }
                else end = mid-1;
            }
              else if(midVal > nums[end]){
                if (target >= nums[beg] and target < midVal){
                    
                    end = mid -1;
                }
                else beg = mid +1;
            }

            // else if (midVal < target && target <= nums[end])
            // {
            //     beg = mid+1;
            //     // if((nums[beg]<nums[end]) && midVal>nums[end])
            //     //     break;  
            //     // if((nums[beg]>nums[end]) && midVal<nums[end])
            //     //     break;                     
            // }
            // else if (midVal > target && target >= nums[beg])
            // {
            //     end = mid-1;
            //     // if((nums[beg]<nums[end]) && midVal<nums[beg])
            //     //     break; 
            //     // if((nums[beg]>nums[end]) && midVal>nums[beg])
            //     //     break;
            // }
            else{
                if(target > midVal) beg = mid + 1;
                else end = mid -1;
            }  
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // disable buffering on stdout completely
    setbuf(stdout, NULL);
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

#endif
    Solution *obj = new Solution();
    //vector<vector<int>> myVec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<int> myVec = {4, 5, 6, 7, 0, 1, 2};
    string str = "((()))*";
    auto ans = obj->search(myVec, 3);
    cout << "\n ans -> " << ans;

    return 0;
}