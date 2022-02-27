/*
Leetcode
 problem-     939. Minimum Area Rectangle

Link - https://leetcode.com/problems/minimum-area-rectangle/
        
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
     int minAreaRect(vector<vector<int>>& points) {
         
         int MinArea = INT_MAX;
         
         unordered_map<int, unordered_set<int> > mapX;
         
         for(const auto& a: points)
         {
             mapX[a[0]].insert(a[1]);
         }
         
         for(int i=0;i<points.size()-1;i++)
         {
             // getting size not performant?
              // if(mapX[points[i][0]].size()<2)
              //     continue;
             
             for(int j=i+1;j<points.size();j++)
             {
                 // int& X1 = points[i][0];
                 // int& Y1 = points[i][1];
                 // int& X2 = points[j][0];
                 // int& Y2 = points[j][1];
                 if( points[i][0] == points[j][0] || points[i][1] == points[j][1])
                     continue;
                 if((abs(points[i][0] - points[j][0]) * abs( points[i][1] - points[j][1])) >= MinArea)
                    continue;
                 
                 // getting size not performant?
                 // if(mapX[ points[j][0] ].size()<2)
                 //     continue;
                 
                 if(mapX[ points[i][0] ].count( points[j][1] ) && mapX[ points[j][0] ].count( points[i][1] ))
                     MinArea = min( abs(points[i][0] - points[j][0]) * abs( points[i][1] - points[j][1] ),MinArea);
             }
         }
         
         if(MinArea==INT_MAX)
             return 0;
         
         return MinArea;
     }
 };
