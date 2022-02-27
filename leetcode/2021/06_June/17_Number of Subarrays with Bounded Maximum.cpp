/*
Leetcode

problem- Number of Subarrays with Bounded Maximum

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3782/

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

// ans1 = https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/1278743/C%2B%2BJavaPython-Easy-to-understand-solution-Clean-and-Concise-O(N)
// ans 2 = https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/1278426/JS-Python-Java-C%2B%2B-or-Easy-Triangular-Number-Solution-w-Explanation
// another very different approach = https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/1278472/C%2B%2B-Simple-and-Easy-Explained-Solution

class Solution {
public:
    int numSubarrayBoundedMax1(vector<int>& nums, int left, int right) {
        int result=0;
        auto func = [](vector<int>& n,int b)->int {
            int c=0;
            int res = 0;
            for(const auto& i:n)
            {
                if(i<=b) res+= ++c;
                else c=0;
            }
            return res;
        };
        
        return func(nums,right) -func(nums,left-1);
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int result=0;

        int mid = 0;
        int low = 0;
        for(const auto& n :nums)
        {
            if(n<=right)
                result += ++mid;
            else
                mid = 0;
            if(n<left)
                result -= ++low;
            else
                low = 0;
        }
        
        return result;
    }
};
