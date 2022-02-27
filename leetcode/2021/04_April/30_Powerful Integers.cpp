/*
Leetcode

 problem- Powerful Integers

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3713/

tags - Linked list

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
    vector<int> powerfulIntegers_other(int x, int y, int bound) {
        unordered_set<int> s;
        for (int i = 1; i <= bound; i *= x) {
            for (int j = 1; i + j <= bound; j *= y) {
                s.insert(i + j);
                if (y == 1) break;
            }
            if (x == 1) break;

        }
        return vector<int>(s.begin(), s.end());
    }
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> result;
        
        if(bound<2)
            return {};
        else if(bound==2)
            return {2};
        int xm=1;
        //result.insert(xm);
            
        int i=0,j=0;
        
        while(true)
        {
            j=0;
            bool flag=false;
            while(true)
            {
                int power = pow(x,i) + pow(y,j);
                //cout<<power<<" ";
                if(power<=bound)
                {
                    result.insert(power);
                    flag=true;
                    ++j;
                }
                else
                    break;
                if(y==1)
                    break;
            }
            if(flag)
                ++i;
            else
                break;
            if(x==1)
                    break;
        }
        vector<int> out(result.begin(),result.end());
        return out;
    }
};
