/*
Leetcode

problem- Find and Replace Pattern

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3750/

tags - medium
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
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        char Pmap[26]={0};
        char Smap[26]={0};
        
        for(auto& s:words)
        {
            memset(&Pmap,0,sizeof(char)*26);
            memset(&Smap,0,sizeof(char)*26);
            bool flag =true;
            for(int i=0;i<s.size();++i)// ch:words[i])
            {
                char ch = s[i];
                //cout<<"-->"<<Pmap[pattern[i]-'a']<<" "<<ch<<endl;
                if(!Pmap[pattern[i]-'a'] && !Smap[ch-'a'])
                {
                    Pmap[pattern[i]-'a'] = ch;
                    Smap[ch-'a'] = pattern[i];
                }
                else if (Pmap[pattern[i]-'a']!= ch || Smap[ch-'a']!= pattern[i])
                {
                    //cout<<"->"<<pattern[i]<<" "<<ch<<endl;
                    flag=false;
                    break;
                }
            }
            if(flag)
                result.push_back(s);
        }
        return result;
    }
};
