/*
Leetcode
problem-   Majority Element
Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/
        
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
    int getGCD(int a, int b)
    {
        if (b == 0) 
            return a; 
        return gcd(b, a % b); 
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int len = coordinates.size();
        int x,x1,y,y1;
        if(len==2)
            return true;

        x=coordinates[0][0];
        y=coordinates[0][1];
        x1=coordinates[1][0];
        y1=coordinates[1][1];
        int num = (y1>y)?y1-y:y-y1;
        int den = (x1>x)?x1-x:x-x1;
        // int div = getGCD(num,den);
        // if(div!=0)
        // {
        //     num/=div;
        //     den/=div;
        // }
        for (size_t i = 2; i < len; i++)        
        {
            x1=coordinates[i][0];
            y1=coordinates[i][1];
            int tnum = (y1>y)?y1-y:y-y1;
            int tden = (x1>x)?x1-x:x-x1;
            // div = getGCD(tnum,tden);
            // if(div!=0)
            // {
            //     tnum/=div;
            //     tden/=div;
            // }
            // if(tnum!=num && tden!=den)
            //     return false;
            if(num*tden!=den*tnum)
                return false;
            
        }
        

        return true;
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
    map<vector<vector<int>>,bool> testCases{ {{{1,2}, {2,3}, {3,4}, {4,5}},true},
                                            {{{1,1}, {2,2}, {3,4}, {4,5},{7,7}},false},
                        {{{-1,1}, {-6,-4}, {-6,2}, {2,0},{-1,-2},{0,-4}},false}
                                            };

    for(auto test:testCases)
    {
        //vector<int>& cvec = const_cast<vector<int>&>(test.first);
        auto ans = obj->checkStraightLine(const_cast<vector<vector<int>>&>(test.first));

        cout << "\n ans -> " << ans << " | expected->"<< test.second;
    }
    
    
  
    return 0;
}