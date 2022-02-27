/*
Leetcode

problem- Reshape the Matrix

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3803/

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
    vector<vector<int>> matrixReshape1(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size();
        int cols = mat[0].size();
        //cout<<"input r="<<rows<<", c="<<cols<<endl;
        if((rows<=r && cols<=c) || (r*c<rows*cols))
            return mat;
        
        int nrows,ncols;
        if(r<rows)
        {
            nrows = r;
            ncols = (rows*cols)/nrows;
        }
        else if(c<cols)
        {
            ncols = c;
            nrows = (rows*cols)/ncols;
        }
        vector<vector<int>> result(nrows,vector<int>(ncols));
        //cout<<"new r="<<nrows<<", c="<<ncols<<endl;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                int tr = (i*cols + j)/ncols;
                int tc = (i*cols + j)%ncols;
                //cout<<"source i,j "<<i<<","<<j<<" dest ="<<tr<<","<<tc<<endl;
                result[tr][tc] = mat[i][j];
            }
        }
        return result;
    }
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        const int& m = mat.size();
        const int& n = mat[0].size();
        const int& o = m * n;
        
        if (r * c != o)
            return mat;
        
        vector<vector<int>> res(r, vector<int>(c, 0));
        
        for (int i = 0; i < o; i++)
            res[i / c][i % c] = mat[i / n][i % n];
        
        return res;
    }
};
