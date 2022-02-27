/*
Leetcode
problem-   Subarray Sum Equals K
Link - https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3307/
        
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
#include <map>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;
typedef vector<int> veci;





class Solution
{
public:
    int subarraySum(vector<int>& nums, int k) {
        //int k=0;
        int currK=0;
        veci sums;
        int sum=0;
        sums.push_back(0);
        for(int n:nums){
            sum+=n;
            sums.push_back(sum);
        }

        for (size_t i = 0; i < sums.size(); i++)
        {
            for (size_t j = i+1; j < sums.size(); j++)
            {
                if(sums[j] - sums[i]==k)
                    currK++;
            }
            
        }
        return currK;

    }
    int subarraySumMap(vector<int>& nums, int k) {
        
        int countK=0;
        unordered_map<int, int> sumMap;
        int sum=0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            sum+=nums[i];
            if(sum==k)
                countK++;
            
            countK += sumMap[sum-k];  // depends on uninitialized value to 0
            sumMap[sum]++;      // again assume initialize to zero 
        }
        return countK;

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
    vector<int> myVec = {1,1,1};
    string str = "((()))*";
    auto ans = obj->subarraySumMap(myVec,2);
    cout << "\n ans -> " << ans;
    //print BST
    
    
    return 0;
}