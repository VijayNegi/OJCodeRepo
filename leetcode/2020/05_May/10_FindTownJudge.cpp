/*
Leetcode
problem-   Find the Town Judge
Link - https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/
        
tags - 
Note - this dosent compile locally, submitted the function code.
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
#include<unordered_set>
#include <map>
#include <list>
#include <utility>
#include <deque>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;

struct input
{
    int N;
    vector<vector<int>> trust;
};


class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        unordered_set<int> _set;
        for (int i = 1; i <= N; i++)
        {
            _set.insert(i);
        }
        vector<int> trustcount(N+1,0);
        for(auto v: trust)
        {
            _set.erase(v[0]);
            trustcount[v[1]]++;
        }
        int judge = -1;
        for(auto s:_set)
        {
            if(trustcount[s]== N-1)
            {
                judge = s;
                break;
            }
                
        }
        

        return judge;
    }
};

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // disable buffering on stdout completely
    setbuf(stdout, NULL);
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

#endif
     Solution *obj = new Solution(); 
    vector<vector<int>> myVec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<char>> myVecChar = {{'1','0','1','0','0'},
                                        {'1','0','1','1','1'},
                                        {'1','1','1','1','1'},
                                        {'1','0','0','1','0'}};
                   
                                      
    //vector<int> myVec = {2,3,1,1,4};
    // string str = "((()))*";
    map<input,int> testCases{ {{2,{{1,2}}},2},
                                {{3,{{1,3},{2,3}}},3},
                                {{3,{{1,3},{2,3},{3,1}}},3}
                          
                                            };

    for(auto test:testCases)
    {
        //vector<int>& cvec = const_cast<vector<int>&>(test.first);
        auto ans = obj->findJudge(test.first.N,const_cast<vector<vector<int>>&>(test.first.trust));

        cout << "\n ans -> " << ans << " | expected->"<< test.second;
    }
    
    
  
    return 0;
}