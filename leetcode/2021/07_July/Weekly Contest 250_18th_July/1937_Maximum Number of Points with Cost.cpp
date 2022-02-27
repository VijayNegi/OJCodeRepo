/*
Leetcode

problem- 1937. Maximum Number of Points with Cost

Link - https://leetcode.com/problems/maximum-number-of-points-with-cost/

tags - Medium , Two Way Array, DP
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

typedef long long ll;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        ll result = 0;
        int rows = points.size();
        int cols = points[0].size();
        vector<ll> dpRow(cols+1,0);
        vector<ll> dpRowPre(cols+1,0);
        
        for(int i=0;i<rows;++i)
        {
            ll maxTillnow = 0;
            for(int k=0;k<cols;++k)
            {
                maxTillnow = max(maxTillnow-1,dpRowPre[k]);
                dpRow[k] = maxTillnow + points[i][k];
            }
            maxTillnow=0;
            for(int k=cols-1;k>=0;--k)
            {
                maxTillnow = max(maxTillnow-1,dpRowPre[k]);
                dpRow[k] = max(maxTillnow + points[i][k],dpRow[k]);
            }
            
            swap(dpRow,dpRowPre);
        }
        for(auto& i:dpRowPre)
            result = max(result,i);
        return result;
    }
};
