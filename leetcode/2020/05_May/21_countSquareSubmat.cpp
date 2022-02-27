/*
Leetcode
problem-   Count Square Submatrices with All Ones
Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/
        
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
#include <deque>
#include <map>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;


class Solution {
public:
    
    int countSquares(vector<vector<int>>& matrix) {
        int matCount = 0;
        if(matrix.size()==0)
            return matCount;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> vec(2,vector(cols,0));
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(i==0 || j==0){
                    vec[1][j] = matrix[i][j];
                    matCount += vec[1][j];  // add 1 if vec positive
                    
                }
                else{
                    if(matrix[i][j]){
                        int minMat = min(min(vec[0][j-1],vec[0][j]),vec[1][j-1]);
                        vec[1][j]=minMat+1;
                        matCount+=vec[1][j];
                        // if(vec[1][j]>1)
                        //     matCount+=vec[1][j]; // one 1 plus one max one
                        // else
                        //     matCount++;
                        
                        //matCount = max(matCount,vec[1][j]);
                    }
                    else{
                        vec[1][j]=0;
                    }
                }
            }
            vec[0].swap(vec[1]);
        }
        return matCount;
    }
};

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // disable buffering on stdout completely
    setbuf(stdout, NULL);
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

#endif
     Solution *obj = new Solution(); 
    vector<vector<int>> myVec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

     map<vector<vector<int>>,int> testCases{ 
                           {{   {1,1,1},
                                {1,1,1},
                                {1,1,1}}, 14},
                           {{   {0,1,1},
                                {1,1,1},
                                {1,1,1}}, 11},
                            {{   {0,1,0},
                                 {1,0,1},
                                 {0,1,0}}, 4}
                           
                                            };
    for(auto test:testCases)
    {
        //vector<int>& cvec = const_cast<vector<int>&>(test.first);
        auto ans = obj->countSquares(const_cast<vector<vector<int>>&>(test.first));

        cout << "\n ans -> " << ans << " | expected->"<< test.second;
    }
  
    return 0;
}