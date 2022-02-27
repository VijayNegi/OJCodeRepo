/*
Leetcode
problem-  Contiguous Array
Link - https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3298/
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
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
using namespace std;

class Solution {
public:
    string shiftLeft(string in, int count)
    {
        // abcdef -> 2 -> cdef | ab
        int len = in.size();
        auto it = in.begin();
        it = it +count;
        string result;
        result.append(it,in.end());
        result.append(in.begin(),it);
        return result;

    }
    string shiftRight(string in,int count)
    {
        // abcdef -> 2 -> ef | abcd
        int len = in.size();
        auto it = in.begin();
        it = it +(len-count);
        string result;
        result.append(it,in.end());
        result.append(in.begin(),it);
        
        return result;

    }
    string stringShift(string s, vector<vector<int>>& shift) {
        string ans = "default";
        int length = shift.size();
        int strSize = s.size();
        int movement =0;
        for (size_t i = 0; i < length; i++)
        {
            if(shift[i][0]==0)
                movement -= shift[i][1];
            else
                movement += shift[i][1];
            
        }    
        bool right = (movement>0)?true:false;   
        movement = movement% strSize;
        cout<<"movement -> "<<movement;
        movement = abs(movement);
        if(right)
            ans = shiftRight(s,movement);
        else
            ans = shiftLeft(s,movement);
        
        
        

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
    Solution* obj = new Solution();
    std::vector<vector<int>> myVec = {{0,1},{1,1},{0,6},{0,1},{0,1}};
    string str = "abcdef";
    string ans = obj->stringShift(str,myVec);
    cout<<"\n ans -> "<<ans;

    return 0;
}