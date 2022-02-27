/*
Leetcode
problem-   Leftmost Column with at Least a One
Link - https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3306/
        https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */
class BinaryMatrix {
    public:
      int get(int x, int y);
      vector<int> dimensions();
};
class Solution
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        // if(binaryMatrix==NULL)
        //     return 0;
        auto dim = binaryMatrix.dimensions();
        int rows = dim[0];
        int cols = dim[1];
        int leftmost = INT_MAX;
        if(rows ==0 || cols==0)
            return 0;
        //leftmost = cols-1;
        int cordR=0,cordC=cols-1;
        while(true){
            if(binaryMatrix.get(cordR,cordC)>0){
                leftmost=cordC;
                if(cordC==0)
                    break;
                cordC--;
            }
            else{
                if(cordR == rows-1)
                    break;
                cordR++;
            }  

        }

    if(leftmost<cols)
        return leftmost;
    return -1;
        
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
    //vector<vector<int>> myVec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<int> myVec = {8,5,1,7,10,12};
    string str = "((()))*";
    auto ans = obj->leftMostColumnWithOne(myVec);
    //cout << "\n ans -> " << ans;
    //print BST
    cout<<"\n Tree -> ";
    
    return 0;
}