/*
Leetcode

problem- Maximum Performance of a Team

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3768/

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

//For a given efficiency, we pick all workers with the same or better efficiency. If the number of workers is greater than k, we pick k fastest workers.
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
     
        vector<pair<int,int>> eng;
        for(int i=0;i<n;i++)
        {
            eng.push_back({efficiency[i],speed[i]});
        }
        sort(eng.begin(),eng.end(),greater<pair<int,int>>());
        long result = 0;
        long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto&[e,s]:eng)
        {
            pq.push(s);
            sum+=s;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            result = max(result, sum * e);
        }
        
        return result % static_cast<int>(1e9+7);
    }
};
