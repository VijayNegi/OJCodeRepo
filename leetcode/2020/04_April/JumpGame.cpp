/*
Leetcode
problem-   Jump Game
Link - https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/531/week-4/3310/
        
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
#include <deque>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canreach=0;
        int len = nums.size();
        for(int i=0;i<len;i++)
        {
            if(canreach<i)
                break;//will never be reachable
            int reachable = nums[i]+i;
            if(canreach<reachable)
                canreach = reachable;
        }
        
        if(canreach>=len-1)
            return true;
        return false;
            
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
    // //vector<vector<int>> myVec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<int> myVec = {2,3,1,1,4};
    // string str = "((()))*";
    auto ans = obj->canJump(myVec);
     cout << "\n ans -> " << ans;
    
  
    return 0;
}