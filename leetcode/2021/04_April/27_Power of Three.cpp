/*
Leetcode

 problem- Power of Three

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3722/

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
    bool isPowerOfThree(int n) {
        
        return n > 0 && (1162261467 % n == 0);
        
        // ====== solution 2
//         if(n==1)
//             return true;
//         long k=3;
        
//         while(n>3)
//         {
//             if(n%3==0)
//                 n/=3;
//             else break;
//         }
//         if(n==3)
//             return true;
//         return false;
        
        // ==== solution 3
//         while(k<=n)
//         {
//             //cout<<k<<" ";
//             if(k==n)
//                 return true;
//             else
//                 k*=3;
            
//         }
//         return false;
    }
};
