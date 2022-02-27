/*
Leetcode
problem-  Contiguous Array
Link - https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3298/
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
    int findMaxLength(vector<int>& nums) {
        
        //Find the max possible substring
        int count = nums.size();
        // as hash table 
        unordered_map<int, int> um; 
        int ones = std::accumulate(nums.begin(), nums.end(), 0);
        cout<<"count->"<<count<<" ,ones->"<<ones<<endl;
        int imin = min(ones,count-ones);
        int maxLen = 2* imin;
        cout<<"maxLen->"<<maxLen<<endl;
        if(count==maxLen)
            return count; 
        std::cout << '\n';
        int sum = 0;
        int ans = 0;
        for (size_t i = 0; i < count; i++)
        {
           sum = (nums[i]==0)?sum-1:sum+1;
           // when subarray starts from index '0' 
            if (sum == 0) 
                ans = i + 1; 
            const auto& it = um.find(sum);
            if(it!= um.end())
            {
                int len = (i - it->second);
                if(len>ans)
                    ans = len; 
            }
            else
            {
                um[sum] = i;
            }
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
    std::vector<int> myVec = {0,1,1};
    int ans = obj->findMaxLength(myVec);
    cout<<"\n ans -> "<<ans;

    return 0;
}