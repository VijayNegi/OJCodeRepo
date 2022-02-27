/*
Leetcode

problem- Range Sum Query 2D - Immutable

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3740/

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

class NumMatrix {
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
      
        int rows = matrix.size();
        int cols = matrix[0].size();
        mat = vector<vector<int>>(rows+1,vector<int>(cols+1,0));//matrix;
        int rowsum=0;
        for(int r=1;r<=rows;r++)
        {
            rowsum=0;
            for(int c=1;c<=cols;c++)
            {
                rowsum+=matrix[r-1][c-1];
                mat[r][c]= rowsum + mat[r-1][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return mat[row2+1][col2+1] - mat[row2+1][col1] - mat[row1][col2+1] +mat[row1][col1];
        // return mat[row2][col2]-
        //     ((col1>0)? mat[row2][col1-1]:0) -
        //     (row1>0?mat[row1-1][col2]:0) +
        //     (row1>0 && col1>0?mat[row1-1][col1-1]:0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
