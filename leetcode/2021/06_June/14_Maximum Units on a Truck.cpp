/*
Leetcode

problem- Maximum Units on a Truck

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3778/

tags - Easy
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
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int>&lhs, const vector<int>& rhs){
            return lhs[1]>rhs[1];
        });
        int result=0;
        for(const auto& b:boxTypes)
        {
            int m = min(b[0],truckSize);
            result += m*b[1];
            truckSize-=m;
            if(truckSize<=0)
                break;
        }
        return result;
    }
};
