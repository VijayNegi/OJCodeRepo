/*
Leetcode
 problem-    Largest Number

Link - https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3472/
        
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

bool shelper(int a, int b)
{
    return (to_string(a) +to_string(b) > to_string(b) + to_string(a));
}

int ghelper1(int a, int b)
{
    int ans=0;
    int preans=0;
    
    while(a > 0 || b > 0)
    {
        int ta = a%10;
        int tb = b%10;
        if(ta>tb)
            preans=1;
        else if(ta<tb)
            preans = -1;
        else
            preans = 0;
        
        a/=10;
        b/=10;
        
        if(a>b)
            preans=-1;
        else if(ta<tb)
            preans = 1;
        else
            preans = 0;
        
        if(preans!=0)
            ans = preans;
        
    }
    return ans;
}
int ghelper(int a,int b)
    {
        int ta = a;
        int tb = b;
        cout<<"\n ghelp "<<a<<" "<<b<<endl;
        int ans = 0;
        if(ta>=10)
        {
            ta = ta%10;
            if(ta==0)  ta = -1;
               
            if(tb>10)
            {
                tb = tb%10;
                if(tb==0)  tb = -1;
                ans = ghelper(a/10,b/10);
            }
            else
            {
                ans = ghelper(a/10,b);
                tb=0; // new
            }
                
        }
        else if(tb>=10)
        {
            tb = tb%10;
            if(tb==0)  tb = -1;
            ans = ghelper(a,b/10);
            ta = 0; // new
        }
        
        if(ans==0)
        {
            if(ta>tb)
                ans=1;
            else if(ta<tb)
                ans = -1;
            else
                ans = 0;
        }
        cout<<"\n ans- "<<ans<<endl;
        return ans;
            
    }
    bool greator(int a, int b)
    {
        int ans = ghelper( a, b);
        if(ans>=0)
            return true;
        return false;
    }
    bool lesser(int a, int b)
    {
        int ans = ghelper( a, b);
        
        if(ans<0)
            return true;
        return false;
    }
class Solution {
public:

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), shelper);
        
        string result;
        for(int v: nums)
        {
            result += to_string(v);
        }
        if(result[0] == '0')
            return "0";
        
        return result;
    }
};
