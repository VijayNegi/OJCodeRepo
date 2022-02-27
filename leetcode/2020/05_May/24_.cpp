/*
Leetcode
problem-   Count Square Submatrices with All Ones
Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/
        
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
    bool flag = true;
public:
    int find_min(vector<int>& vec,int s,int e)
    {
        if(flag)
        {
            //cout<<"true - ";
            int min(501);//loc(0);
            for(int i = s;i < e; i++ )
            {
                if(vec[i]<vec[i+1] && vec[i]<vec[i-1])
                {
                   return i;
                }
            }
            
        }
        flag = false;

        {
            //cout<<"false - ";
            int max(0),loc(0);
            for(int i = s;i < e; i++ )
            {
                if(vec[i]>max)
                {
                   max = vec[i];
                    loc = i;
                }
            }
            if(loc!=e-1)
                return ++loc;
            else if(loc!=s)
                return --loc;
            return loc;
        }
        return 0;
    }
    int maxCoins(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        else if(nums.size()==1)
            return nums[0];
        int coins = 0;
        flag = true;
        while(nums.size()>2)
        {
            int r = find_min(nums,1,nums.size()-1);
            cout<<" r - "<<r;
            coins += nums[r-1]*nums[r]*nums[r+1];
            nums.erase(nums.begin()+r);
        }
        cout<<endl;
        if(nums[0]>nums[1])
        {
            coins += nums[0]*nums[1] + nums[0];
        }
        else
            coins += nums[0]*nums[1] + nums[1];
        
        return coins;
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

     map<vector<int>,int> testCases{ 
                          //{   {3,1,5,8},167}
                          //,{   {9,76,64,21},116718}
                          // ,{   {1,1,1},3}
                           {   {4,3,1,5,1,8,9,6},937}
                         // ,{   {4,3,1,5,89,8,9,6,66,23,1,99,141,9},2157882}
                           
                                
                           
                                            };
    for(auto test:testCases)
    {
        //vector<int>& cvec = const_cast<vector<int>&>(test.first);
        auto ans = obj->maxCoins(const_cast<vector<int>&>(test.first));

        cout << "\n ans -> " << ans << " | expected->"<< test.second;
    }
  
    return 0;
}