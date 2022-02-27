/*
Leetcode
 problem-     Evaluate Division

Link - https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3474/
        
tags - graph, dfs

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
    unordered_map<string,vector<pair<string,double>>> mval;
    vector<double> result;
    unordered_map<string, int> visited;
    
    double dfs(string start, string end)
    {
        //cout<<"->"<<start<<" - "<< end<<endl;
        double res = -1;
        if(!mval.count(start))
            return -1;
        if(start==end)
            return 1;
        if(!visited.count(start) )
        {
            auto vdest = mval[start];
            visited[start] = 1;
            
            for(auto dest : vdest)
            {
                if(dest.first==end)
                {
                    res = dest.second;
                }
                else if(dest.first!=end)
                {
                    double res1 = dest.second;
                    res1 *= dfs(dest.first,end);
                    if(res1>0)
                    {
                        res = res1;
                    }
                }
            }
        }
        else
        {
            res = -1;
        }
        //cout<< " res - "<< res<<endl;
        return res;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        mval.clear();
        result.clear();
        
        for(int i=0; i<equations.size(); i++)
        {
            mval[equations[i][0]].push_back({equations[i][1],values[i]});
            mval[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        
        for(int i=0;i<queries.size();i++)
        {
            visited.clear();
            double ans = dfs(queries[i][0],queries[i][1]);
            if(ans >= 0)
                result.push_back(ans);
            else
                 result.push_back(-1);
        }
        
        return result;
    }
};
