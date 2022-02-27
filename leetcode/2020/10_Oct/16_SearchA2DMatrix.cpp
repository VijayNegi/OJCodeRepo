/*
Leetcode
 problem-     Search a 2D Matrix

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3497/

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

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int len,wid;
        len = matrix.size();
        if(len>0)
            wid = matrix[0].size();
        else
            return false;
        if(wid<1)
            return false;
        
        if(target<matrix[0][0] || target> matrix[len-1][wid-1])
            return false;
        
        int x,y;
        x= wid-1;
        y = 0;
        while(x>=0 && y < len)
        {
            if(target == matrix[y][x])
                return true;
            else if(target < matrix[y][x])
                --x;
            else
                ++y;
        }
        return false;
    }
};
