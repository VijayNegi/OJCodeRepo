/*
Leetcode

problem- 1880. Check if Word Equals Summation of Two Words

Link - https://leetcode.com/contest/weekly-contest-243/problems/check-if-word-equals-summation-of-two-words/

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
    int numVal(string &s)
    {
        int result=0;
        int digit=1;
        for(int i=s.size()-1;i>=0;--i)
        {
            result+= (s[i]-'a')*digit;
            digit*=10;
        }
        return result;
    }
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        
        int a= numVal(firstWord);
        int b = numVal(secondWord);
        int c = numVal(targetWord);
        cout<<a<<" "<<b<<" "<<c<<endl;
        return (a+b==c)? true:false;
        
    }
};
