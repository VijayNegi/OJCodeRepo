/*
Leetcode

problem- 1910. Remove All Occurrences of a Substring

Link - https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

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
public:
    string removeOccurrences(string s, string part) {
        
        int len=s.size();
        int i=0,j=0;
        int lenP = part.size();
        i = lenP;
        j = lenP;
        while(i<len)
        {
            //cout<<j<<" "<<s.substr(0,j)<<endl;
            if(j>=lenP)
            {
                if(s.substr(j-lenP,lenP) == part)
                    j= j-lenP;
            }
            s[j++] = s[i++];
        }
        if(j>=lenP)
        {
            if(s.substr(j-lenP,lenP) == part)
                j= j-lenP;
        }
        return s.substr(0,j);
    }
};
