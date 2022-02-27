/*
Leetcode

problem- Group Anagrams

Link - https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3887/

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
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t.append(counter[c], c + 'a');
        }
        return t;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mAna;
        
        for(auto n: strs)
        {
            mAna[strSort(n)].push_back(n);
        }
        
        vector<vector<string>> result;
        for(auto vec:mAna)
        {
            result.push_back(vec.second);
        }
        return result;
    }
};
