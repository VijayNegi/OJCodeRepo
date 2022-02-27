/*
Leetcode

problem- 1882. Process Tasks Using Servers

Link - https://leetcode.com/contest/weekly-contest-243/problems/process-tasks-using-servers/

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

typedef pair<int,int> pInt;
typedef pair<int,pInt> ppInt;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> result;
        
        priority_queue<pInt, vector<pInt>, greater<pInt>> free;
        priority_queue<ppInt,vector<ppInt>, greater<ppInt>> busy;
        for(int i=0;i<servers.size();++i)
            free.emplace(servers[i],i);
        
        int t=0;
        int tsk=0;
        while(tsk<tasks.size())
        {

            while( !busy.empty() && busy.top().first <=t)
            {
                free.emplace(busy.top().second);
                busy.pop();
            }
            
            while(tsk<=t && !free.empty() &&  tsk<tasks.size())
            {
                busy.emplace(t+tasks[tsk],free.top());
                result.push_back(free.top().second);
                free.pop();
                ++tsk;
            }
            
            if(free.empty())
                t=busy.top().first;
            else
                ++t;
            
        }
        return result;
    }
};
