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
    vector<int> _coins;
    int _count;
    int _amount;
    int _start;
    void helper(int sum)
    {
        for(int i = _start;i<_coins.size();i++)
        {
            int coin = _coins[i];
            //cout<<" "<<coin<<" ";
            _start = i;
            if(coin+sum < _amount)
            {
                helper(coin + sum);
                
            }
            else if(coin+sum == _amount)
            {
                _count++;
                //cout<<" | ";
                return;
            }
            else
                return;
        }
    }
    int change1(int amount, vector<int>& coins) {
        if(amount==0)
            return 1;
        //reset count
        _count = 0;
        _start = 0;
        
        _coins = coins;
        sort(_coins.begin(),_coins.end());
        _amount = amount;
        helper(0);
        return _count; 
    }
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(int coin:coins)
        {
            for(int i=coin;i<= amount;i++)
            {
                if(i - coin >=0 )
                {
                    dp[i]+= dp[i-coin];
                }
            }
        }
        return dp[amount];
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

     map<pair<int,vector<int>>,int> testCases{ 
                        
                           //{   {{7, 0 }, {4, 4 }, {7, 1}, {5, 0}, {6, 1}, {5, 2}},0},
                           //{   {{0,0},{6,2},{5,5},{4,3},{5,2},{1,1},{6,0},{6,3},{7,0},{5,1}},0}
                           {{5,{1,2,5}}, 4},
                           {{0,{}}, 1}
                            };
    for(auto test:testCases)
    {
        //vector<int>& cvec = const_cast<vector<int>&>(test.first);
        auto ans = obj->change(test.first.first,const_cast<vector<int>&>(test.first.second));

        cout << "\n ans -> " << ans << " | expected->"<< test.second;
    }
  
    return 0;
}