/*
Leetcode

problem- Count of Smaller Numbers After Self

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3792/

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

// read this -https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/138154/The-C%2B%2B-merge-sort-template-for-pairs-'i'-'j'-problem
// Least Significant Bit of i
#define LSB(i) ((i) & -(i))
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int range = 2e5;
        const int offset = 1e4 + 1;
        vector<int> BIT(range,0);
        int n = nums.size();
        vector<int> result(n);
        
        auto update = [&](int idx,int val){
            while(idx<range)
            {
                BIT[idx] += val;
                idx += idx & -idx;
            }
        };
        auto sum = [&](int idx){
            int sum=0;
            while(idx>0)
            {
                sum +=BIT[idx];
                idx -= idx & -idx;
            }
            return sum;
        };
        
        for(int i=n-1;i>=0;i--)
        {
            result[i]= ( sum(nums[i] + offset -1 )  );
            update(nums[i] + offset ,1);
        }
        
        
        return result;
    }
};
