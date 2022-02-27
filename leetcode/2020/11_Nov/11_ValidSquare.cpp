/*
Leetcode

 problem-     Valid Square

Link - https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3527/

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
      int getSquaredDistance(vector<int> &a, vector<int> &b) {
        int dx = a[0]-b[0];
        int dy = a[1]-b[1];
        return dx*dx + dy*dy;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        vector<vector<int>> points;
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);
        
        unordered_map<int,int > lenMap;
        
        for(int i=0;i<points.size();++i)
        {
            for(int j=i+1;j<points.size();++j)
            {
                //int x = abs(points[i][0]-points[j][0]);
                //int y = abs(points[i][1]-points[j][1]);
                //int len = x*x + y*y;
                lenMap[getSquaredDistance(points[i],points[j])]++;
            }
        }
        
        if(lenMap.count(0)==1)
            return false;
        
        if(lenMap.size()==2)
            return true;
        return false;
    }
};
