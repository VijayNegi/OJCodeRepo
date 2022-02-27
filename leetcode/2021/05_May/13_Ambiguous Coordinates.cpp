/*
Leetcode

problem- Ambiguous Coordinates

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3741/

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
    bool zeroCheckFront(string& s)
    {
        //check if both strings are valid
        //1. check for leading zero
        if(s.size()==1)
            return true;
        for(const auto& c:s)
        {
            if(c=='0')
                return false;
            else
                break;
        }
        return true;
    }
    vector<string> permutate(string& s)
    {
        vector<string> result;
        if(zeroCheckFront(s))
            result.push_back(s);
        int len=s.size();
        if(len>1)
        {
            string temp=s;
            temp.insert(0,1,'.');
            for(int i=1;i<len;i++)
            {
                
                temp[i-1]= temp[i];
                temp[i] = '.';
                if(zeroCheckTrail(temp))
                    result.push_back(temp);
            }
        }
        return result;
    }
    // Not mine
    vector<string> findAll(string S){
        int n = S.size();
        if(n == 0 ||(n > 1 && S[0] == '0' && S[n-1] == '0')) return {};
        if(n > 1 && S[0] == '0') return {"0." + S.substr(1)};
        if(S[n-1] == '0') return {S};
        vector<string> res{S};
        for(int i = 1; i < n; i++){
            res.push_back(S.substr(0, i) + "." + S.substr(i));
        }
        return res;
     }
    bool zeroCheckTrail(string s)
    {
        //check zero trail after decimal
        int len = s.size();
        //we know size>1
        if((s[0]=='0' && s[1]!='.'))
            return false;
        for(int i=len-1;i>=0;i--)
        {
            if(s[i]=='0')
                return false;
            else
                break;
        }
        return true;
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> result;
        int len = s.size();
        for(int i=1;i<s.size()-2;i++)
        {
            string s1 = s.substr(1,i);
            string s2 = s.substr(i+1,len-2-i);
            //if(!zeroCheckFront(s.substr(1,i),s.substr(i+1,len-2-i)))
                //continue;
            //result.push_back("("+s.substr(1,i) +", "+s.substr(i+1,len-2-i)+")");
            auto per1 = findAll(s1);//permutate(s1);
            auto per2 = findAll(s2);//permutate(s2);
            for(const auto& ss1:per1)
            {
                for(const auto& ss2:per2)
                    result.push_back("("+ss1 +", "+ss2+")");
            }
        }
        return result;
    }
};
