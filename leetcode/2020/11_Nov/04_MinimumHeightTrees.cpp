/*
Leetcode

 problem-     Minimum Height Trees

Link - https://leetcode.com/explore/featured/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3519/

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
    
    void dfs(unordered_map<int,vector<vector<int>>>& emap,int edge,vector<int>& result,int parent,int depth)
    {
        //cout<<"edge-> "<<edge<<" p->"<<parent<<endl;
        for(const auto& a:emap[edge])
        {
            for(const auto& node:a)
            {
                if(node!=edge && node!=parent)
                    dfs(emap,node,result,edge,depth+1);
                result[edge] = max(result[edge],depth);
            }
        }
    }
    vector<int> findMinHeightTrees1(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<vector<int>>> _map;
        vector<int> result(n,0);
        for(const auto& a: edges)
        {
            _map[a[0]].push_back(a);
            _map[a[1]].push_back(a);
        }
        
        auto it = _map.begin();
        while(it!= _map.end())
        {
            if(it->second.size()==1) // corner node
            {
                dfs(_map,it->first,result,INT_MAX,1);
            }
            ++it;
            // for(const auto& a:result)
            // {
            //     cout<<a<<" - ";
            // }
            // cout<<endl;
        }
        
        vector<int> fin;
        int min= INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(result[i]==min)
                fin.push_back(i);
            else if(result[i]<min)
            {
                min=result[i];
                fin.clear();
                fin.push_back(i);
            }
        }
        return fin;
    }
    // new impl
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<unordered_set<int>> adj(n);
        
        for(const auto& a:edges)
        {
            adj[a[0]].insert(a[1]);
            adj[a[1]].insert(a[0]);
        }
        // Corner case
        vector<int> current;
        if (n == 1) {
          current.push_back(0);
          return current;
        }
        for(int i=0;i<n;++i)
        {
            if(adj[i].size()==1)
                current.push_back(i);
        }
        
        while(!current.empty())
        {
            vector<int> next;
            for(const auto& node: current)
            {
                for(const auto& neighbour: adj[node])
                {
                    adj[neighbour].erase(node);
                    if(adj[neighbour].size()==1)
                        next.push_back(neighbour);
                }
            }
            
            if(next.empty())
                break;
            current = next;
            
        }
        
        return current;
    }
};
