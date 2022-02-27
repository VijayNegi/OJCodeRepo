/*
Leetcode
problem-  Last Stone Weight
Link - https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/529/week-2/3297/
tags -

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        
        std::map<int,int, greater <int>> _data;
        for (auto c : stones)
            _data[c]++;
        
        
        int stone1 = 0,stone2 = 0;
        
        while(_data.size()>1)
        {
            auto i = _data.begin();
            //auto e = _data.end();
            if(i->second & 1 ){ // i.e. its odd , even will be cancel out anyway
                stone1 = i ->first;
                i = _data.erase(i);  // remove it now
            }
            else {// even cancel out  
                i = _data.erase(i);
                continue;
            }
            
            // get second stone
            stone2 = i ->first;
            _data[i->first]--;
            if(_data[i->first]==0)
                i = _data.erase(i);
            _data[stone1-stone2]++;
        }
        if(_data.size()==1)
        {
            if(_data.begin()->second & 1 )
                return _data.begin()->first;
            return 0;
        }
        else
            return stone1;
        
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
    Solution* obj = new Solution();
    std::vector<int> myVec = {2,7,4,1,8,1};
    int ans = obj->lastStoneWeight(myVec);
    cout<<"\n ans -> "<<ans;
    return 0;
}