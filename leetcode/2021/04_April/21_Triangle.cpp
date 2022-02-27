/*
Leetcode

 problem- Triangle

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3715/

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
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int size= triangle.size();
        vector<int> result(size,INT_MAX);
        result[0]=triangle[0][0];
        for(int i=1;i<size;i++)
        {
            //cout<<i<<endl;
            for(int j=triangle[i].size()-1;j>=0;j--)
            {
                //cout<<" j-"<<j<<endl;
                result[j] = min(result[j],(j>0)?result[j-1]:INT_MAX);
                result[j]+= triangle[i][j];
            }
        }
        
        int minTotal=INT_MAX;
        for(const auto& num:result)
        {
            minTotal = min(minTotal,num);
        }
        
        return minTotal;
        
    }
};
