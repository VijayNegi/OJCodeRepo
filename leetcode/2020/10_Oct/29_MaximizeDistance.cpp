/*
Leetcode

 problem-     Maximize Distance to Closest Person

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/563/week-5-october-29th-october-31st/3512/

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
    int maxDistToClosest(vector<int>& seats) {
        int prev =-1;
        int ans=1;
        for(int i=0;i<seats.size();++i)
        {
            if(seats[i]==1)
            {
                if(prev>=0)
                {
                    int temp = (i-prev)/2;
                     ans = (temp>ans)?temp:ans;
                     prev=i;
                }
                else
                {
                    ans = (i>ans)?i:ans;
                     prev = i;
                }
            }
        }
        //if(seats[seats.size()-1]!=1)
        {
            int temp = (seats.size()-1-prev);
            ans = (temp>ans)?temp:ans;
        }
        return ans;
    }
};
