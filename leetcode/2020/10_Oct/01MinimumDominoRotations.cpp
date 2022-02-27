/*
Leetcode

problem-     1007. Minimum Domino Rotations For Equal Row

Link - https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

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
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int VecSize = A.size();
        if(VecSize==1)
            return 0;
        vector<int> faceCount(7,0);
        for(int i=0;i<VecSize;i++)
        {
            faceCount[A[i]]++;
            faceCount[B[i]]++;
        }
        int Max = 0;
        for(int i=0;i<faceCount.size();i++)
            Max = (faceCount[Max]<faceCount[i])? i: Max;
       
        if(VecSize>faceCount[Max])
            return -1;
        int result(0);
        for(int i=0;i<VecSize;i++)
        {
            if(A[i]!= Max && B[i]!=Max)
                return -1;
            if(A[i] != Max)
                result++;
        }
        //result = min(result,VecSize - result );// vecsize - (face[Max]- (VecSize-result))
        result = min(result,VecSize - (faceCount[Max]- (VecSize-result)) );
        return result;
    }
};
