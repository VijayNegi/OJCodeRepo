/*
Leetcode

 problem- Number of Submatrices That Sum to Target

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3711/

tags - Sliding window, Dynamic programming

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
    int Sum(vector<vector<int>>& matrix, int i,int ii,int j,int jj )
    {
        //cout<<matrix[ii][jj]<<"-"<<matrix[ii][j-1]<<"-"<<matrix[i-1][jj]<<"+"<<matrix[i-1][j-1]<<endl;
        return matrix[ii][jj] - matrix[ii][j-1]- matrix[i-1][jj] + matrix[i-1][j-1];
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols=0;
        if(rows)
            cols = matrix[0].size();
        vector<vector<int>> pre(rows+1, vector<int>(cols+1,0));
        int result=0;
        int rowsum=0;
        for(int i=1; i<rows+1 ; i++)
        {
            rowsum=0;
            for(int j=1; j<cols+1; j++)
            {
                rowsum+=matrix[i-1][j-1];
                pre[i][j]+= rowsum;
                //if(i>0)
                pre[i][j]+= pre[i-1][j];
                //if(j>0)
                //    pre[i][j]+=pre[i][j-1];
            }
        }
        map<int,int> count;
        for(int i=1;i<rows+1;i++)
        {
            for(int ii=i; ii<rows+1; ii++)
            {
                count.clear();
                count[0]++;
                for(int j=1; j<cols+1; j++)
                {
                    //for(int jj=j; jj<cols+1; jj++)
                    {
                        
                        int sum = Sum(pre,i,ii,1,j);
                        //cout<<i<<" "<<ii<<" "<<j<<" s-"<<sum<<endl;
                        if(count.find(sum-target)!=count.end())
                           result+=count[sum-target];
                        count[sum]++;
                    }
                }
            }
        }
        return result;
    }
};
