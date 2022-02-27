/*
Leetcode
problem-   Queue Reconstruction by Height
Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3352/
        
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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        list<pair<int,int>> _sort;
        int size = people.size();
        vector<vector<int>> result(size,vector(2,-1));
        sort(people.begin(),people.end());
        int lastHeight=-1;
        int sub = 0;
        for(int i=0;i<people.size();i++)
        //for(vector<int> p : people)
        {
            vector<int> p = people[i];
            int loc=0,fre=0;
            if(p[0]==lastHeight)
                sub--;
            else
                sub = 0;
            
            int add = 1 + sub;
            while(fre!=p[1]+add)
            {
                if(result[loc++][0]==-1)
                    fre++;
            }
            lastHeight = p[0];
            result[loc-1] = p;
        }
        
        return result;
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

     map<vector<vector<int>>,int> testCases{ 
                        
                           //{   {{7, 0 }, {4, 4 }, {7, 1}, {5, 0}, {6, 1}, {5, 2}},0},
                           {   {{0,0},{6,2},{5,5},{4,3},{5,2},{1,1},{6,0},{6,3},{7,0},{5,1}},0}
                           
                         // ,{   {4,3,1,5,89,8,9,6,66,23,1,99,141,9},2157882}
                           
                                
                           
                                            };
    for(auto test:testCases)
    {
        //vector<int>& cvec = const_cast<vector<int>&>(test.first);
        auto ans = obj->reconstructQueue(const_cast<vector<vector<int>>&>(test.first));

        cout << "\n ans -> ";
        for(auto a: ans)
        {
            cout<< a[0]<<","<<a[1]<<"| ";
        }
        //cout << "\n ans -> " << ans << " | expected->"<< test.second;
    }
  
    return 0;
}