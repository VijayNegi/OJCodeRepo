/*
Leetcode
 problem-     Remove Duplicate Letters

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3491/

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
    string removeDuplicateLetters(string s) {
        vector<int> count(27,0);
        vector<bool> visited(27,false);
        
        for(char c: s)
         count[c-'a']++;
        string result("");
        for(char c:s)
        {
            count[c-'a']--;
            
            if(visited[c-'a'])
                continue;
            
            while(!result.empty() && result.back()>c && count[ result.back() - 'a']>0)
            {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result +=c;
            visited[c-'a'] = true;
        }
        
        return result;
    }
};
