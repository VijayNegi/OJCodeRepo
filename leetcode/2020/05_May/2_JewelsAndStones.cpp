/*
Leetcode
problem-   JewelsAndStones.cpp
Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/
        
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
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> jewel,stones;
        for (size_t i = 0; i < J.size(); i++)
        {
            jewel[J[i]]=1;
        }
        for (size_t i = 0; i < S.size(); i++)
        {
            stones[S[i]]++;
        }
        int jewelCount=0;
        for(auto sto:stones)
        {
            if(jewel.count(sto.first))
                jewelCount+=sto.second;
        }
        
        return jewelCount;  
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
    map<pair<string,string>,int> testCases{ {{"aA","aAAbbbb"},3},
                                            {{"A","aAAbbbb"},2},
                                            {{"","aAAbbbb"},0},
                                            {{"aA",""},0},
                                             {{"",""},0},
                                            {{"aA","bbbbbbb"},0}
                                            };

    for(auto test:testCases)
    {
        auto ans = obj->numJewelsInStones(test.first.first,test.first.second);

        cout << "\n ans -> " << ans << " | expected->"<< test.second;
    }
    
    
  
    return 0;
}