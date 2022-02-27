/*
Leetcode

problem- 1878. Get Biggest Three Rhombus Sums in a Grid

Link - https://leetcode.com/contest/biweekly-contest-53/problems/get-biggest-three-rhombus-sums-in-a-grid/

tags - Medium
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
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> result;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                //cout<<"[i][j]="<<i<<":"<<j<<endl;
                
                result.push_back(grid[i][j]);
                
                int side=1;
                while(true)
                {
                    if(j-side<0 || j+side>=cols || i+2*side >= rows ) //invalid rhombus
                        break;
                    //cout<<"side="<<side<<endl;
                    int k=-1;
                    int sum=0;
                    
                    while(++k<side)
                    {
                        sum += grid[i+side -k][j-side +k]; // left move to top
                        sum += grid[i+k][j+k]; // top to right
                        sum += grid[i+2*side - k][j-k]; // bottom to left
                        sum += grid[i+side+k][j+side-k]; // right
                    }
                    ++side;
                   
                    result.push_back(sum);

                }
            }
        }
        std::sort(result.begin(),result.end());
        vector<int> res;
        res.push_back(result.back());
        result.pop_back();
        
        while(!result.empty() && res.size()<3)
        {
            if(res.back()!=result.back() )
                res.push_back(result.back());
            result.pop_back();
        }
        
        return res;
    }
};
