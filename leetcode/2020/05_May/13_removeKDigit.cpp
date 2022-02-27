/*
Leetcode
problem-   Remove K Digits
Link - https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/
        
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
#include <map>
#include <list>
#include <utility>
#include <deque>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;


class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int ssize = num.length();
        if(k>=ssize)
            return "0";

        int i=0;
        while(k!=0)
        {
            if(i+1<num.length())
            {
                if((num[i+1]-'0') < (num[i]-'0'))
                {
                    num.erase(i,1); // delete one num
                    k--;
                    i = (i>0)? i-1 : i;
                }
                else
                    i++;
            }
            else
            {
                num.pop_back();
                k--;
            }
        }
        //remove leading zero
        while (num.length() > 1)
        {
            if(num[0]=='0')
                num.erase(0,1);
            else
                break;
            
        }
        return num;
        
    }
};

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // disable buffering on stdout completely
    setbuf(stdout, NULL);
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

#endif
     Solution *obj = new Solution(); 
    vector<vector<int>> myVec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<char>> myVecChar = {{'1','0','1','0','0'},
                                        {'1','0','1','1','1'},
                                        {'1','1','1','1','1'},
                                        {'1','0','0','1','0'}};
                   
                                      
    //vector<int> myVec = {2,3,1,1,4};
    // string str = "((()))*";
    map<pair<string, int>,string> testCases{ {{"12345",1},"1234"},
                           {{"12315",1},"1215"},
                            {{"171819",2},"1119"},
                            {{"123234345",1},"12234345"},
                            {{"1200456",3},"45"},
                            {{"123456",3},"123"}
                                            };

    for(auto test:testCases)
    {
        //vector<int>& cvec = const_cast<vector<int>&>(test.first);
        auto ans = obj->removeKdigits(test.first.first,test.first.second);

        cout << "\n ans -> " << ans << " | expected->"<< test.second;
    }
    
    
  
    return 0;
}