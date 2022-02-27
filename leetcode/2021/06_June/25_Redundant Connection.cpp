/*
Leetcode

problem- Redundant Connection

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3791/

tags - Tarjan algorithm
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
    void dfs(int v,int parent,int &t,vector<int>& lowestRechable,vector<int>& discovered,vector<vector<int>>& connect )
    {
        if(discovered[v]>=0)   // if already visited return
                return;
        else            // if not visited assign id and lowest rechable is itself
        {
            discovered[v] = t;
            lowestRechable[v] = t;
            ++t;
        }
        for(const auto& c: connect[v])      // traverse all edges
        {
            if(c!=parent)       // dont visit parent i.e. you cant go back.
            {
                // visit neighbour and take the lowest rechable.
                dfs(c,v,t,lowestRechable,discovered,connect);
                lowestRechable[v] = min(lowestRechable[c],lowestRechable[v]);
            }
        }
        return;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> connect(n+1,vector<int>());
        for(const auto& e:edges)
        {
            connect[e[0]].push_back(e[1]);
            connect[e[1]].push_back(e[0]);
        }
        vector<int> low(n+1,-1),des(n+1,-1),result;
        int t=0;
        
        
        dfs(1,-1,t,low,des,connect);
        //vector<int> result;
        for(const auto& e:edges)
        {
            if(low[e[0]] == low[e[1]])
            //if(des[e[0]]!= low[e[0]] || des[e[1]] != low[e[1]])
                result = e;
        }
        return result;
    }
};
