/*
Leetcode
problem-   Bitwise AND of Numbers Range
Link - https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3308/
        https://leetcode.com/problems/bitwise-and-of-numbers-range/
tags - bit manipulation

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



class Solution
{
public:
    int rangeBitwiseAnd(int m, int n) {
        int ptwo=0;
        int value=0;
        int diff = n-m; 
        
        while(m!=n){
            m = m>>1;
            n = n>>1;
            ptwo++;
        }
        return n<<ptwo;
        // for (size_t i = 0; i < 31; i++)
        // {
        //     if(ptwo<m){
        //         if(ptwo>diff)
        //             value|=ptwo;
        //     }
        //     // else if(ptwo<=n )
        //     //      value&=ptwo;
        //     else 
        //         break;
            
        //     ptwo = ptwo<<1;
        // }
        // return n & m & value;
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
    auto ans = obj->rangeBitwiseAnd(5,7);
    cout << "\n ans -> " << ans;
 
  
    return 0;
}