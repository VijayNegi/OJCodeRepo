/*
Leetcode

problem- 1898. Maximum Number of Removable Characters

Link - https://leetcode.com/problems/maximum-number-of-removable-characters/

 tags - Medium
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
    bool checksubsequnence(const string& s,const string& p)
    {
        int i=0;
        int j=0;
        while(i < s.size() && j < p.size())
        {
          if(p[j]==s[i])
              ++j;
          ++i;
        }
        return j==p.size();
    }
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = s.size();
        int np = p.size();
        int nr = removable.size();
        if(nr==0)
            return 0;
        if(n==np) return 0;
        
        int result=0;
        int l = min(n-np,nr); // chars can be removed
        int st=0;
        int ed=l-1;
        while(st<=ed)
        {
            // No need to copy string you can mantain set of removed locations??
            // https://leetcode.com/problems/maximum-number-of-removable-characters/discuss/1268446/Binary-Search
            string t = s;
            int mid = (ed+st)/2;
            for(int i=0;i<=mid;++i)
                t[removable[i]] = 'A';
            if(!checksubsequnence(t,p))
            {
                result = mid-1;
                ed = mid-1;
            }
            else
            {
                result = mid;
                st=mid+1;
            }
        }
        return result+1;
    }
};
