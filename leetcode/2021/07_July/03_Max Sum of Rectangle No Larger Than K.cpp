/*
Leetcode

problem- Max Sum of Rectangle No Larger Than K

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3801/

tags - Hard
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

//https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/83599/Accepted-C%2B%2B-codes-with-explanation-and-references
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        //vector<vector<int>> prefix(rows+1,vector<int>(cols+1,0));
        int result=INT_MIN;
        
        for(int c=0;c<cols;++c)
        {
            vector<int> csum(rows,0);
            for(int c1=c;c1<cols;++c1)
            {
                for(int r=0;r<rows;++r)
                {
                    csum[r] += matrix[r][c1];
                }
                
                set<int> comm;
                comm.insert(0);
                int currSum=0,maxSum=INT_MIN;
                for(auto s: csum)
                {
                    currSum+=s;
                    auto it = comm.lower_bound(currSum - k );
                    if(it!= comm.end()) maxSum = max(maxSum, currSum - *it);
                    comm.insert(currSum);
                }
                result = max(result,maxSum);
            }
        }
        return result;
        
    }
};
