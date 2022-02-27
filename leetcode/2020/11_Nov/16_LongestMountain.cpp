/*
Leetcode

 problem-     Longest Mountain in Array

Link - https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3533/

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
    int longestMountain(vector<int>& A) {
        bool inc=true;
        int curr=0;
        int maxm=0;
        if(A.size()<3)
            return 0;
        for(int i=0;i<A.size()-1;++i)
        {
            if(inc && A[i]< A[i+1])   // uphill
                curr++;
            else if( !inc && A[i]>A[i+1])  // downhill
                curr++;
            else if(inc && A[i]>A[i+1] && curr >0)  // top
            {
                inc=false;
                curr++;
            }
            else
            {
                if(!inc && curr>=2)
                    maxm = max(maxm,curr+1);
                curr=0;
                inc=true;
                if(A[i]< A[i+1])
                    curr++;
            }
        }
        if(!inc && curr>=2)
            maxm = max(maxm,curr+1);
        return maxm;
    }
};
