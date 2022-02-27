/*
Leetcode

 problem- Brick Wall

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3717/

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
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int> BrickSum;
        
        int height = wall.size();
        int SumTotal=0;
        int wallHeight= height;
        while(height--)
        {
            int sum=0;
            for(const auto& brick:wall[height])
            {
                sum+=brick;
                ++BrickSum[sum];
            }
            if(!SumTotal)
                SumTotal = sum;
        }
        int result=0;
        for(const auto& it:BrickSum)
        {
            if(it.first !=SumTotal && it.second> result)
                result= it.second;
        }
        return wallHeight-result;
    }
};
