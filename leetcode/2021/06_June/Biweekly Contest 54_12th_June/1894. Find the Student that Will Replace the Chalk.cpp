/*
Leetcode

problem- 1894. Find the Student that Will Replace the Chalk

Link - https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

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
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        sum = accumulate(chalk.begin(),chalk.end(),sum);
        k = k%sum;
        int result = 0;
        for(int i=0;i<chalk.size();++i)
        {
            if(chalk[i]<=k)
                k-=chalk[i];
            else
                return i;
        }
        return result;
    }
};
