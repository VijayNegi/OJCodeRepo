/*
Leetcode

problem- 1935. Maximum Number of Words You Can Type

Link - https://leetcode.com/problems/maximum-number-of-words-you-can-type/

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
    int canBeTypedWords(string text, string brokenLetters) {
        int result=0;
        vector<int> broken(27,0);
        for(auto& c:brokenLetters)
        {
            broken[c-'a'] = 1;
        }
        int idx=0;
        int n = text.size();
        bool foundBroken = false;
        while(idx<n)
        {
            if(text[idx]==' ')
            {
                if(!foundBroken)
                    ++result;
                foundBroken = false;
            }
            else if(broken[text[idx]-'a'])
                foundBroken = true;
            ++idx;
                
        }
        if(!foundBroken)
            ++result;
        return result;
    }
};
