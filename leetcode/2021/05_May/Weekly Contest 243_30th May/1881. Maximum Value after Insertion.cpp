/*
Leetcode

problem- 1881. Maximum Value after Insertion

Link - https://leetcode.com/contest/weekly-contest-243/problems/maximum-value-after-insertion/

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
    string maxValue(string n, int x) {
        
        string result;
        
        if(n[0]=='-')
        {
            result = n + to_string(x);
            for(int i=1;i<n.size();++i)
            {
                if(n[i]>'0'+x)
                {
                    result = n.substr(0,i) + to_string(x) + n.substr(i,n.size()-i);
                    break;
                }
            }
            
        }
        else
        {
            result = n + to_string(x);
            for(int i=0;i<n.size();++i)
            {
                if(n[i]<'0'+x)
                {
                    result = n.substr(0,i) + to_string(x) + n.substr(i,n.size()-i);
                    break;
                }
            }
            
        }
        
        return result;
    }
};
