/*
Leetcode

 problem- Furthest Building You Can Reach

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3721/

tags - Priority Queue, Heap

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
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int curr=0;
        int len = heights.size();
        long sum=0;
        vector<int> incDiff;
        while(curr<len-1)
        {
            int diff = heights[curr+1] - heights[curr];
            if(diff<=0)
            {
                ++curr;
                continue;
            }
            else
            {
                incDiff.push_back(diff);
                sum+=diff;
                push_heap(incDiff.begin(), incDiff.end());
                ++curr;
                if(sum>bricks)
                {
                    if(ladders)
                    {
                        int bri = incDiff.front();
                        pop_heap(incDiff.begin(), incDiff.end());
                        incDiff.pop_back();
                        sum-=bri;
                        --ladders;
                    }
                    else
                    {
                        --curr;
                        break;
                    }
                    
                }
            }
        }
        return curr;
    }
};
