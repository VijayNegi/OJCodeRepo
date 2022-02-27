/*
Leetcode

problem- Count Vowels Permutation

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3802/

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

class Solution {
public:
    int countVowelPermutation(int n) {
        const int mod = 1e9+7;
        vector<int> curr(5,1) ;
        
        for(int i=2;i<=n;++i)
        {
            vector<int> next(5,0);
            
            next[0] = ((curr[1] + curr[2])%mod + curr[4])%mod;
            next[1] = (curr[0] + curr[2])%mod;
            next[2] = (curr[1] + curr[3])%mod;
            next[3] = (curr[2])%mod;
            next[4] = (curr[2] + curr[3])%mod;
            
            // e follow a;
//             next[1] = curr[0];
            // a,i follow e;
//             next[0] = curr[1];
//             next[2] = curr[1];

//             next[0] = (next[0] + curr[2])%mod;
//             next[1] = (next[1] + curr[2])%mod;
//             next[3] = curr[2];
//             next[4] = curr[2];

//             next[2] = (next[2] + curr[3])%mod;
//             next[4] = (next[4] + curr[3])%mod;

//             next[0] = (next[0] + curr[4])%mod;
            curr = next;
        }
        int sum=0;
        for(int k=0;k<5;++k)
        {
            //cout<<k<<" ="<<curr[k]<<", ";
            sum  = (sum + curr[k])% mod;
        }
        //cout<<endl;
        
        return sum;
    }
};
