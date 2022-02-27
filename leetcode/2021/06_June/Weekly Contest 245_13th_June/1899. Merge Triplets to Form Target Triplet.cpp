/*
Leetcode

problem- 1899. Merge Triplets to Form Target Triplet

Link - https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

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

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> result(3,false);
        for(const auto& tri:triplets)
        {
            if(tri[0]==target[0] && tri[1]<=target[1] && tri[2]<=target[2])
                result[0] = true;
            if(tri[0]<=target[0] && tri[1]==target[1] && tri[2]<=target[2])
                result[1] = true;
            if(tri[0]<=target[0] && tri[1]<=target[1] && tri[2]==target[2])
                result[2] = true;
            
        }
        return result[0] && result[1] && result[2];
    }
};
