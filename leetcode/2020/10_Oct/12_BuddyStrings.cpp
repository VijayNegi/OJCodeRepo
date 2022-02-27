/*
Leetcode
 problem-     Buddy Strings

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3492/

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
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
            return false;
        vector<int> diff;
        vector<int> count(26,0);
        //diff[0] = 0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=B[i])
            {
                //diff[0]++;
                diff.push_back(i);
            }
            count[A[i] - 'a']++;
        }
        if(diff.size()>2 || diff.size() == 1) // will handle 0 case differently
            return false;
        if(diff.empty())
        {
            for(const auto& a : count)
                if(a>1) return true;
        }
        else if(A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]])
            return true;
        
        return false;
        
    }
};
