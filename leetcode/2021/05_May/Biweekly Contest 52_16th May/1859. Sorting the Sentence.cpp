/*
Leetcode

problem- 1859. Sorting the Sentence

Link - https://leetcode.com/contest/biweekly-contest-52/problems/sorting-the-sentence/

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
    string sortSentence(string s) {
        vector<string> res(10);
        int pos=0;
        while(true)
        {
            int sp = s.find(' ',pos);
            if(sp>s.size())
                break;
            res[stoi(s.substr(sp-1,1))] = s.substr(pos,sp-pos-1);
            pos = sp+1;
        }
        if(pos<s.size()-1)
        {
            res[stoi(s.substr(s.size()-1,1))] = s.substr(pos,s.size()-pos-1);
        }
        string result;
        result.append(res[1]);
        for(int i= 2;i<10;i++)
        {
            if(res[i].empty())
                break;
            result.append(" "+res[i]);
        }
        return result;
    }
};
