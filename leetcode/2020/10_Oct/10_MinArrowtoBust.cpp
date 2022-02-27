/*
Leetcode
 problem-     Minimum Number of Arrows to Burst Balloons

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3490/

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

bool sortx(vector<int>& a, vector<int>& b)
{
    if(a[0]< b[0])
        return true;
    else if(a[0]==b[0] && a[1] > b[1])
        return true;
    return false;
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(points.size()<2)
            return points.size();
        sort(points.begin(),points.end(), sortx);
        int result(0);
        
        int i(0);
        int l(0),r(0);
        bool reset(true);
        while(i<points.size())
        {
            if(reset) // no balloons selected;
            {
                l = points[i][0];
                r = points[i][1];
                i++;
                reset=false;
            }
            else
            {
                //if(points[i][1]- l >= 0 && r - points[i][0] >= 0) // intersection
                if(r>=points[i][0])
                {
                    //update l and r
                    l = max(points[i][0],l);
                    r = min(points[i][1],r);
                    // move to next balloon
                    i++;
                }
                else // no intersection, clean previous balloons and update arrows
                {
                    reset=true;
                    result++;
                }
            }
        }
        result++; // last case;
        
        return result;
        
    }
};
