/*
Leetcode
 problem-   Gas Station

Link - https://leetcode.com/explore/featured/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3470/
        
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tcost =0;
        int tgas = 0;
        tcost = std::accumulate(cost.begin(), cost.end(), 0);
        tgas = std::accumulate(gas.begin(), gas.end(), 0);
        if(tgas<tcost)
            return -1;
        int index = 0;
        int sum = 0;
        int minSum = INT_MAX;
        for(int i=0;i<gas.size()*2;i++)
        {
            int mi=i%gas.size();
            int temp = gas[mi]-cost[mi];
            sum +=temp;
            if(sum<=minSum)
            {
                minSum = sum;
                index = mi;
            }
        }
        return (index+1)%gas.size();
    }
};
