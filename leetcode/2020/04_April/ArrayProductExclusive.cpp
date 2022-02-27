/*
Leetcode
problem-   Product of Array Except Self
Link - https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3300/
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
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
using namespace std;

class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int product=1;
        for(auto n:nums)
        {
            ans.push_back(product);
            product *= n;
        }

        product = 1;
        for(int i = nums.size()-1 ;i>=0;i--)
        {

            ans[i] *=product;
            product *= nums[i];
        }
        return ans;
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
    Solution* obj = new Solution();
    std::vector<int> myVec = {2,2,2,2};
    string str = "abcdef";
    auto ans = obj->productExceptSelf(myVec);
    //cout<<"\n ans -> "<<ans;
    for(auto n:ans)
        {
            cout<<n<<" -> ";
        }
    return 0;
}