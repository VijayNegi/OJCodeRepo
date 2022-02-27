/*
Leetcode
 problem-   Cheapest Flights Within K Stops

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3360/
        
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
    int _visited[100];
    int _src,_dst,_cost;
    vector<list<vector<int>>> graph;
    void helper(int toVisit,int cost,int depth)
    {
        //cout<<"Before-"<<toVisit<<"-visted?-"<<_visited[toVisit]<<endl;
        if(!_visited[toVisit] && depth >= 0)
        {
            
            if(toVisit==_dst)
            {
                //cout<<"found-"<<toVisit<<endl;
                if(cost < _cost)
                    _cost = cost;
                return;
            }
            if(cost>_cost)
                return;
            _visited[toVisit] = 1;
            
            for(auto a: graph[toVisit])
            {
                //cout<<"visiting->"<<toVisit<<" a[0]-"<<a[0]<<" a[1]-"<<a[1]<<" a[2]-"<<a[2]<<endl;
                helper(a[1],cost + a[2],depth-1);
                //cout<<endl;
            }
            
            // for(int i=0;i<graph[toVisit].size();i++)
            // {
            //     //int tCost = graph[toVisit][i][2];
            //     helper(graph[toVisit][i][1],cost + graph[toVisit][i][2],depth-1)
            //}
            
            
            _visited[toVisit] = 0;
        }
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        _src = src;
        _dst = dst;
        _cost = INT_MAX;
        memset(_visited,0,sizeof _visited);
        graph.reserve(n);
        for(int i=0;i<n;i++)
        {
            //cout<<i<<"->"<<_visited[i]<<endl;
            graph.push_back({});
        }
        for(auto a : flights)
        {
            //cout<<"edge-"<<a[0]<<", "<<a[1]<<", "<<a[2]<<endl;
            graph[a[0]].push_back(a);
        }
        helper(src,0,K+1);
        
        return (_cost==INT_MAX)?-1:_cost;
    }
    
};
