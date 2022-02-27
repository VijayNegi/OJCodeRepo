/*
Leetcode
 problem-    Interval List Intersections
Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3338/
        
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
#include <map>
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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int sizeA = A.size();
        int sizeB = B.size();
        if(!sizeA || !sizeB)
            return ans;
        ans.reserve(max(sizeA,sizeB));
        int i(0),j(0);
        while(i < sizeA && j < sizeB)
        {
            if ( A[i][1] - B[j][0] >= 0 && B[j][1] - A[i][0] >= 0 ) // intersect
            {
                int start = max(A[i][0],B[j][0]);
                int end = min(A[i][1],B[j][1]);
                ans.push_back({start,end});
                if(end == A[i][1])
                    i++;
                else
                    j++;
            }
            else if(A[i][1] < B[j][1])
                i++;
            else
                j++;
            
        }
        return ans;
    }
};
