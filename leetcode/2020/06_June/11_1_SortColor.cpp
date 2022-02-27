/*
Leetcode
 problem-   Sort Colors

Link - https://leetcode.com/problems/sort-colors/
        
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
#include <vector>
#include <deque>
#include <map>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;

class Solution {
    void swap(int& a, int& b)
    {
        int temp = a ;
        a = b;
        b = temp;
    };
public:
    void sortColors(vector<int>& nums) {
        // we know 1's will be in between
        // so keep track of start of 2's and 1's or end of 0
        int stTwo(nums.size()),stOne(-1);
        
        int Len(nums.size()-1);
        int start(0);
        while(true)
        {
            if(Len >=0 && nums[Len]==2)
            {
                Len--;
                stTwo--;
            }
            else
                break;
        }
        while(true)
        {
            if(start < nums.size() && nums[start]==0)
            {
                start++;
                stOne++;
            }
            else
                break;
        }
        
        
        for(int i = start; i <= Len; i++)
        {
            if(nums[i]==0)
            {
                //cout<<"\n1,";
                swap(nums[stOne++ + 1], nums[i]);
                //stOne++;
            }
            else if(nums[i]==2 && i < stTwo)
            {
                //cout<<"\n2,";
                swap(nums[i],nums[stTwo-- - 1]);
                //stTwo--;
                i--;
            }
            
            // cout<<endl;
            // for(int j=0;j <nums.size();j++)
            // {
            //     cout<<" - "<<nums[j];
            // }
        }
        
    }
};
