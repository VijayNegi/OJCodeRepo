/*
Leetcode

problem- Count Primes

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3738/

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
    int countPrimes(int n) {
        vector<int> v(n+1,false);
        int result=0;
        for(int i=2;i*i<n;i++)
        {
            if(v[i])
                continue;
            for(int j=i*i;j<n;j+=i)
            {
                v[j]=true;
            }
        }
        
        for(int i=2;i<n;i++)
        {
            if(!v[i])
            {
                //cout<<" "<<i;
                ++result;
            }
        }
        return result;
    }
};
