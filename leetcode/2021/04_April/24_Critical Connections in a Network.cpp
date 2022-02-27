/*
Leetcode

 problem- Critical Connections in a Network

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3719/

tags - Graph, Hard, Strongly connected components (SSC)

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
    vector<int> low;
    vector<int> discover;
    int time;
    vector<vector<int>> edges;
    vector<vector<int>> result;
    vector<int> parents;
    void dfs(int parent)
    {
        //cout<<"parent-"<<parent<<endl;
        discover[parent] = low[parent] = time++;
        
        for(const auto& node: edges[parent])
        {
            if(discover[node] == -1) // not visited before
            {
                parents[node] = parent;
                dfs(node);
                
                if(low[node]> discover[parent]) // no back link
                    result.push_back({parent,node});
                low[parent] = min(low[parent], low[node]);
            }
            else if(node != parents[parent])// should be a check for strongly connected components
                low[parent] = min(low[parent],low[node]); // for SCC change low[node] to discover[node]
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        low = vector<int>(n,-1);
        discover = vector<int>(n,-1);
        parents = vector<int>(n,-1);
        edges = vector<vector<int>>(n);
        time=0;
        
        for(const auto& edge : connections)
            edges[edge[0]].push_back(edge[1]),edges[edge[1]].push_back(edge[0]);
        
        
        for(int i=0;i<n;i++)
            if(discover[i]==-1)
                dfs(i);
       
        
        return result;
    }
};
