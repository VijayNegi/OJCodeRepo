/*
Leetcode

problem- Minimum Moves to Equal Array Elements II

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3748/

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

typedef long long int ll;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size ();
        sort (nums.begin(), nums.end());
        int mid = n/2, i = 0, count = 0;
        for (i = 0; i < n; i++)
            count += abs (nums [i] - nums [mid]);
        return count;
    }
};
