/*
Leetcode

problem- 1897. Redistribute Characters to Make All Strings Equal

Link - https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

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
    bool makeEqual(vector<string>& words) {
        int hash[26]={};
        int n = words.size();
        if(n<2)
            return true;
        for(int i=0;i<n;++i)
        {
            for(auto c:words[i])
                ++hash[c-'a'];
        }
        for(int i=0;i<26;i++)
        {
            if(hash[i]>0)
                if(hash[i]%n!=0)
                    return false;
        }
        return true;
            
    }
};
