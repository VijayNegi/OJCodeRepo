/*
Leetcode

problem- 1861. Rotating the Box

Link - https://leetcode.com/contest/biweekly-contest-52/problems/rotating-the-box/

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
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int cols = box[0].size();
        
        vector<vector<char>> result(cols,vector<char>(rows,'.'));
        
        for(int r=0;r<rows;r++)
        {
            int stonesTillNow=0;
            for(int c=0;c<cols;c++)
            {
                if(box[r][c]=='#')
                    stonesTillNow++;
                else if(box[r][c]=='*') // print stones to result.
                {
                    result[c][rows-r-1] = '*'; // mark obstacle
                    //Print stone
                    for(int i=c-1;i>= c - stonesTillNow;i--)
                    {
                        result[i][rows-r-1] = '#';
                    }
                    //reset stones count
                    stonesTillNow=0;
                }
                
                
            }
         
            {
                //Print stone
                for(int i=cols-1;i>= cols - stonesTillNow;i--)
                {
                    result[i][rows-r-1] = '#';
                }
            }
        }
        return result;
    }
};
