/*
Leetcode
problem-   Island Perimeter
 
Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3383/
        
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
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                //Vertical
                if(i==0)
                {
                    if(grid[i][j]==1)
                        count++;
                }
                else
                {
                    if(grid[i][j] + grid[i-1][j]==1)
                        count++;
                }
                
                if(i==grid.size()-1)
                {
                    if(grid[i][j]==1)
                        count++;
                }
                
                //Horizontal
                
                if(j==0)
                {
                    if(grid[i][j]==1)
                        count++;
                }
                else
                {
                    if(grid[i][j] + grid[i][j-1]==1)
                        count++;
                }
                
                if(j==grid[0].size()-1)
                {
                    
                    if(grid[i][j]==1)
                        count++;
                }
                
            }
        }
        return count;
    }
};
