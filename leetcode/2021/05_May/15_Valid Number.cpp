/*
Leetcode

problem- Valid Number

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3744/

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
public:
    bool checkDecimal(string s)
    {
        //cout<<"d->"<<s<<endl;
        bool result = true;
        if(s.empty())
            return false;
        int i=0;
        if(s[0]=='+' || s[0]=='-')
            ++i;
        int digit = 0;
        int deci = 0;
        while(i<s.size())
        {
            char ch = s[i];
            // check sign

            if(ch=='.' )
            {
                ++deci;
                if(deci>1)
                    return false;
            }
            else if (ch>='0' && ch<='9')
            {
                ++digit;
            }
            else
                return false;
            ++i;
    
        }
        if(/*deci==1 &&*/ digit>0)
            return true;
        else
            return false;
        
        return result;
    }
    bool checkInt(string s)
    {
        //cout<<"i->"<<s<<endl;
        bool result = true;
        
        int i=0;
        if(s[0]=='+' || s[0]=='-')
            ++i;
        int digit = 0;
        while(i<s.size())
        {
            char ch = s[i];
            if (ch>='0' && ch<='9')
            {
                ++digit;
            }
            else
                return false;
            ++i;
    
        }
        if(digit>0)
            return true;
        else
            return false;
        
        return result;
    }
    bool isNumber(string s) {
        bool result = false;
        int pos = s.find('e');
        if(pos>s.size())
            pos = s.find('E');
        if(pos>s.size())
        {
            result = checkDecimal(s);
            // if(!result)
            //     result = checkInt(s);
        }
        else
        {
            result = checkDecimal(s.substr(0,pos));
            if(result)
                result = checkInt(s.substr(pos+1,s.size()-pos-1));
        }
        
        return result;
    }
};
