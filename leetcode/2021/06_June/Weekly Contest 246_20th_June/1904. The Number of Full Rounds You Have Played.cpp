/*
Leetcode

problem- 1904. The Number of Full Rounds You Have Played

Link - https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/

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
    int numberOfRounds(string startTime, string finishTime) {
        int result=0;;
        int sth = stoi(startTime.substr(0,2));
        int stq = stoi(startTime.substr(3,2));
        int fth = stoi(finishTime.substr(0,2));
        int ftq = stoi(finishTime.substr(3,2));
        
        int stround = (stq+14)/15;
        int ftround = (ftq)/15;
        
        // if(startTime<finishTime)
        // {
        //     if(fth - sth==0)
        //         result += max(ftround-stround,0);
        //     else
        //     {
        //         result += 4*(fth-sth-1);
        //         result += ftround + 4-stround;
        //     }
        // }
        // else
        // {
        //     result += 4*(24 + fth - sth);
        //     result += ftround - stround;
        // }
        
        result += ftround-stround;
        result += 4*(fth-sth);
        if(startTime>finishTime)
            result += 24*4;
        
        
        
        return max(result,0);
    }
};
