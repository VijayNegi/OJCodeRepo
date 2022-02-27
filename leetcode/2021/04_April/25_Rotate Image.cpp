/*
Leetcode

 problem- Rotate Image

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3720/

tags - Matrix

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
    void rotate(vector<vector<int>>& matrix) {
        int temp;
        int size = matrix.size();
        --size;
        int matSize=0;
        
        int topX=0,topY=0;
        int leftX=0,leftY=size;
        int rightX=size, rightY=0;
        int bottomX=size, bottomY=size;
        
        while(true)
        {
            
            temp = matrix[topY][topX];
            matrix[topY][topX] = matrix[leftY][leftX];
            matrix[leftY][leftX] = matrix[bottomY][bottomX];
            matrix[bottomY][bottomX] = matrix[rightY][rightX];
            matrix[rightY][rightX] = temp;
            
            topX++;
            
            leftY--;
            bottomX--;
            rightY++;
            if(topX==size-matSize)
            {
                matSize++;
                topX=matSize,topY=matSize;
                leftX=matSize,leftY=size-matSize;
                rightX=size-matSize, rightY = matSize;
                bottomX= size-matSize, bottomY = size-matSize;
            }
            if(matSize*2>=size)
                break;
        }
    }
};
