/*
Leetcode
problem-   First Unique Character in a String
Link - https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/
        
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
#include <map>
#include <list>
#include <utility>
#include <deque>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> _map(26,INT_MAX);

        for (size_t i = 0; i < s.size(); i++)
        {
            if(_map[s[i] - 'a'] == INT_MAX)
                _map[s[i] - 'a'] = i;
            else
                _map[s[i] - 'a'] = s.size();
        }
        int ans = INT_MAX;
        for(auto m : _map)
        {
            ans = min(m,ans);
        }

        if(ans<s.size())
            return ans;

        return -1;
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
    map<string,int> testCases{ {"leetcode",0},
                            {"loveleetcode",2}
                        
                                            };

    for(auto test:testCases)
    {
        auto ans = obj->firstUniqChar(test.first);

        cout << "\n ans -> " << ans << " | expected->"<< test.second;
    }
    
    
  
    return 0;
}