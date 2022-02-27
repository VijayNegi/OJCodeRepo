/*
Leetcode

problem- 1860. Incremental Memory Leak

Link - https://leetcode.com/contest/biweekly-contest-52/problems/incremental-memory-leak/

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
    vector<int> memLeak(int memory1, int memory2) {
        vector<int> result(3,0);
        int i=1;
        while(true)
        {
            if(memory1<i && memory2<i)
                break;
            if(memory1>=memory2)
            {
                memory1-=i;
            }
            else
            {
                memory2-=i;
            }
            ++i;
        }
        result[0]=i;
        result[1]= memory1;
        result[2]= memory2;
        return result;
    }
};
