/*
Leetcode

 problem-     Find the Smallest Divisor Given a Threshold

Link - https://leetcode.com/explore/featured/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3521/

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

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long sum=0;
        int end = 0;
        for(auto const& a:nums)
        {
            sum+=a;
            end = max(end,a);
        }
        
        int start = sum/threshold;
        if(start==0)
            return 1;
        long tsum=0;
        
        int mid;
        while(start<end)
        {
            mid = (start+end)/2;
            tsum=0;
            for(auto const& a: nums)
                tsum+=(a+mid-1)/mid;
            if(tsum<=threshold)
                end = mid;
            else
                start = mid +1;
        }
        return end;
    }
};
