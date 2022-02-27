/*
Leetcode

 problem-     Flipping an Image

Link - https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3526/

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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if(A.size()==0)
            return A;
        if(A[0].size()==0)
            return A;
        
        int rows= A.size();
        int cols= A[0].size();
        int cols2= (cols+1)/2;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols2;j++)
            {
                if(j==(cols-j-1))//single col
                {
                    A[i][j] = 1-A[i][j];
                }
                else
                {
                    if(A[i][j] == A[i][cols-j-1])
                    {
                        A[i][j] = 1-A[i][j];
                        A[i][cols-j-1] = A[i][j];
                    }
                }
            }
        }
        return A;
    }
};
