/*
Leetcode

problem- Swim in Rising Water

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3785/
// Note custom comparetor for priority queue
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

typedef pair<int,int> pii;
typedef pair<int,pii> ppii;
class Solution {
    int rows,cols;
public:
    int swimInWater(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};
        
        auto valid = [&](int r1,int c1) {return (r1>=0 && r1<rows && c1>=0 && c1<cols);};
        auto comp = [](const ppii& l,const ppii& r){ return l.first > r.first; };
        priority_queue<ppii,vector<ppii>,decltype(comp)> pq {comp};

        pq.push({grid[0][0],{0,0}});
        grid[0][0]=-1;
        
        while(!pq.empty())
        {
            const auto t = pq.top();
            pq.pop();
            int r = t.second.first;
            int c = t.second.second;
            if(r==rows-1 && c==cols-1)
                return t.first;
            
            for(int i=0;i<4;++i)
            {
                if(valid(r +dr[i] ,c + dc[i] ) && grid[r+dr[i]][c+ dc[i]]!=-1)
                {
                    pq.push({ max(t.first, grid[r+dr[i]][c+ dc[i]]),{r+dr[i],c+ dc[i]}});
                    grid[r+dr[i]][c+ dc[i]]=-1;
                }
            }
        }
        return 0;
    }
};
