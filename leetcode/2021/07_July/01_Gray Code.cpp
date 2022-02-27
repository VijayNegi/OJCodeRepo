/*
Leetcode

problem- Gray Code

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3799/

tags - Medium
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
    vector<int> grayCode1(int n) {
        int k=  1<<n;
        vector<int> result(k);
        for(int i=0;i<k;++i)
        {
            result[i] = i^(i>>1);
        }
        return result;
    }
    
    vector<int> grayCode(int n) {
        int k = 1<<n;
        vector<int> result(k);
        result[0] = 0;
        result[1] = 1;
        for(int i=2;i<=n;++i)
        {
            int l=0;
            int h = (1<<i) -1;
            while(l<h)
            {
                result[h--] = result[l++] | (1<<(i-1));
            }
        }
        
        return result;
    }
};
