/*
Leetcode

problem- Isomorphic Strings

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3811/

tags - Easy
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
    bool isIsomorphic1(string s, string t) {
        vector<char> mapS(256,' ');
        vector<char> mapT(256,' ');
        
        for(int i=0;i<s.size();++i)
        {
            if(mapS[s[i]]!= ' ' &&  mapS[s[i]] != t[i])
                return false;
            if(mapT[t[i]]!= ' ' && mapT[t[i]] != s[i])
                return false;
            if(mapS[s[i]]==' ')
            {
                mapS[s[i]] = t[i];
                mapT[t[i]] = s[i];
            }
        }
        
        return true;
    }
    //save location ease conditions
    bool isIsomorphic(string s, string t) {
        vector<int> mapS(256,-1);
        vector<int> mapT(256,-1);
        for(int i=0;i<s.size();++i)
        {
            if(mapS[s[i]] != mapT[t[i]])
                return false;
            mapS[s[i]] = i;
            mapT[t[i]] = i;
                
        }
        return true;
    }
};
