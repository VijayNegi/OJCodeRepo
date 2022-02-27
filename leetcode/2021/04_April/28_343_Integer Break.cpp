/*
Leetcode

 problem- 343. Integer Break

Link - https://leetcode.com/problems/integer-break/

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
    int integerBreak(int n) {
        int result=0;
        int k=2;
        while(true)
        {
            int mod= n%k;
            if(mod==0)
            {
                int r = pow(n/k,k);
                if(r>result)
                    result=r;
                else
                    break;
            }
            else
            {
                int r = pow(n/k,k-mod);
                r*=pow(n/k +1,mod);
                if(r>result)
                    result=r;
                else
                    break;
            }
            ++k;
        }
        
        return result;
    }
};
