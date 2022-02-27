/*
Leetcode

problem- 336. Palindrome Pairs

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3777/

tags - Hard
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
    bool checkPalindrome1(const string& ss)
    {
        int s=-1,e=ss.size();
        while(++s<=--e)
            if(ss[s]!=ss[e])
                return false;
        return true;
    }
    bool checkPalindrome(const string&& ss)
    {
        int s=-1,e=ss.size();
        while(++s<=--e)
            if(ss[s]!=ss[e])
                return false;
        return true;
    }
    bool checkPalindrome2(const string& s1, const string& s2)
    {
        
        int l1=s1.size(),l2 = s2.size();
        int s=0,e=l2-1;
        while(s<l1 && e>=0)
        {
            if(s1[s]!=s2[e])
                return false;
            ++s; --e;
        }
        if(s==l1 && e!=-1)
        {
            s=0;
            while(s<=e)
            {
                if(s2[s]!=s2[e])
                    return false;
                ++s; --e;
            }
        }
        else if(s!=l1 && e==-1)
        {
           e = l1-1;
            while(s<=e)
            {
                if(s1[s]!=s1[e])
                    return false;
                ++s; --e;
            }
        }
        return true;
    }
public:
    //optimized  244ms
    vector<vector<int>> palindromePairs1(vector<string>& words) {
        vector<vector<int>> result;
        vector<vector<int>> start(26,vector<int>());
        vector<vector<int>> end(26,vector<int>());
        int hasEmpty = -1;
        for(int i =0;i<words.size();++i)
        {
            if(words[i].size()<1)
            {
                hasEmpty = i;
                continue;
            }
            int currStart = words[i].front() - 'a';
            int currEnd = words[i].back()-'a';
            for(int j=0;j<end[currStart].size();j++)
            {
                int k = end[currStart][j];
                if(checkPalindrome2(words[i],words[k]))
                    result.push_back({i,k});
            }
            for(int j=0;j<start[currEnd].size();j++)
            {
                int k = start[currEnd][j];
                if(checkPalindrome2(words[k] , words[i]))
                    result.push_back({k,i});
            }
    
             start[currStart].push_back(i);
             end[currEnd].push_back(i);
        }
        if(hasEmpty>=0)
        {
            for(int i =0;i<words.size();++i)
            {
                if(words[i].size())
                {
                    if(checkPalindrome1(words[i]))
                        result.push_back({hasEmpty,i}), result.push_back({i,hasEmpty});
                }
            }
        }
        
        return result;
    }
    //bruteForce 724ms
    vector<vector<int>> palindromePairs2(vector<string>& words) {
        vector<vector<int>> result;
        for(int i=0;i<words.size();++i)
        {
            for(int j=i+1;j<words.size();++j)
            {
                if(checkPalindrome2(words[i],words[j]))
                    result.push_back({i,j});
                if(checkPalindrome2(words[j],words[i]))
                    result.push_back({j,i});
            }
            
        }
        return result;
    }
    // final optimized prefix,sufix
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string,int> m;
        for(int i=0;i<words.size();++i)
        {
            m[string(words[i].rbegin(),words[i].rend())] = i;
        }
        for(int i=0;i<words.size();++i)
        {
            for(int j=0;j<=words[i].size();++j)
            {
                string pre = words[i].substr(0,j);
                string suf = words[i].substr(j);
                if(j>0 && checkPalindrome1(pre) && m.find(suf)!=m.end() && m[suf]!=i)
                    result.push_back({m[suf],i});
                if(checkPalindrome1(suf) && m.find(pre)!=m.end() && m[pre]!=i)
                    result.push_back({i,m[pre]});
            }
        }
        return result;
    }
};
