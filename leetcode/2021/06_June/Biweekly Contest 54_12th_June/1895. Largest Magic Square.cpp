/*
Leetcode

problem- 1895. Largest Magic Square

Link - https://leetcode.com/problems/largest-magic-square/

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
    bool ismagic(vector<vector<int>>& grid, int i,int j, int s, int sum)
    {
        //cout<<"ismagic "<<i<<", "<<j<<" size="<<s<<" sum="<<sum<<endl;
        int rs =0;
        vector<int> cs(s+1,0);
        int ds1 = 0; // this /
        for(int r = i;r<= i+s;++r)
        {
            rs=0;
            for(int c = j;c<=j+s;++c)
            {
                rs+=grid[r][c];
                cs[c-j]+=grid[r][c];
                if(r+c == i+s+j)
                {
                    //cout<<"diag+="<<grid[r][c]<<endl;
                    ds1+=grid[r][c];
                }
            }
            if(rs!=sum)
            {
                //cout<<"rowsum false"<<endl;
                return false;
            }
        }
        for(int k=0;k<=s;++k)
            if(cs[k]!=sum)
            {
                cout<<"colsum false"<<endl;
                return false;
            }
        if(ds1!=sum)
        {
            
            cout<<"diag false="<<ds1<<endl;
            return false;
        }
        //cout<<"ismagic=true"<<endl;
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        
//         vector<vector<int>> ver = grid;
//         vector<vector<int>> hor = grid;
        
//         for(int i = 0; i< grid.size();++i)
//         {
//             for(int j=0;j<grid[0].size();++j)
//             {
//                 if(i>0)
//                     ver[i][j]+=ver[i-1][j];
//                 if(j>0)
//                     hor[i][j]+=hor[i][j-1];
//             }
//         }
        int rows = grid.size();
        int cols = grid[0].size();
        
        int ms = min(grid.size(),grid[0].size());
        //cout<<"ms="<<ms<<endl;
        
        int result = 1;
            
        for(int i = 0; i< rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                //cout<<"i,j="<<i<<","<<j<<endl;
                int hs,vs,ds;
                hs=vs=ds=grid[i][j];
                for(int s=1;s<ms;++s)
                {
                    if(i+s>=rows || j+s>=cols)
                        break;
                    hs += grid[i][j+s];
                    vs += grid[i+s][j];
                    ds += grid[i+s][j+s];
                    if(hs!=vs || vs !=ds)
                        continue;
                    // check if this is magic square
                    if(ismagic(grid,i,j,s,hs))
                    {
                        result = max(result,s+1);
                    }
                }
            }
        }
        return result;
    }
};
