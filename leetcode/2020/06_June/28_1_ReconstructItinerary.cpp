/*
Leetcode
problem-   Coin Change 2
Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3353/
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
#include <deque>
#include <map>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        vector<string> ans(tickets.size() + 1);
        unordered_map<string, vector<string>> _map;
        
        for(const auto& v: tickets)
        {
            _map[v[0]].push_back(v[1]);
        }
        for(auto a: _map)
        {
            std::sort(begin(a.second),end(a.second));
        }
        
        string from = "JFK";
        string to = "";
        ans.push_back(from);
        while(true)
        {
            auto it = _map.find(from);
            if(it != _map.end())
            {
                ans.push_back((it->second)[0]);
                if(it->second.size()==1)
                    _map.erase(it);
                else
                {
                    (it->second).erase((it->second).begin());
                }
            }
        }
        return ans;
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

     map<vector<vector<string>>,vector<string>> testCases{ 
                            {{{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}},
                                    {"JFK", "MUC", "LHR", "SFO", "SJC"}}
                           //{   {{7, 0 }, {4, 4 }, {7, 1}, {5, 0}, {6, 1}, {5, 2}},0},
                           //{   {{0,0},{6,2},{5,5},{4,3},{5,2},{1,1},{6,0},{6,3},{7,0},{5,1}},0}
                           //{{{1,2,5}}, 4},
                           //{{0,{}}, 1}
                            };
    for(auto test:testCases)
    {
        //vector<int>& cvec = const_cast<vector<int>&>(test.first);
        auto ans = obj->findItinerary(const_cast<vector<vector<string>>&>(test.first));

        //cout << "\n ans -> " << ans << " | expected->"<< test.second;
        cout << "\n ans -> ";
        for(auto a: ans)
        {
            cout<< a<<" | ";
        }
        cout << "\n ept -> ";
        for(auto b: test.second)
        {
            cout<< b<<" | ";
        }
    }
  
    return 0;
}