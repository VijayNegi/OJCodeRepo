/*
Leetcode

problem- Kth Smallest Element in a Sorted Matrix

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3805/

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

// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/861912/Sharing-My-Both-C%2B%2B-Sol.-Using-Binary-Search-Heap
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        while(left<right)
        {
            int mid = left + (right-left)/2;
            int count = 0;
            int row = n-1;
            int col = 0;
            while(row>=0 && col<n)
            {
                if(matrix[row][col]<=mid)
                {
                    count += row + 1;
                    ++col;
                }
                else
                    --row;
            }
            if(count<k)
            {
                left = mid + 1;
            }
            else
                right = mid;
        }
        
        
        return left;
    }
};
