/*
Leetcode

problem- Longest String Chain

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3746/

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
    void swap(string& s,int a,int b)
    {
        if(a!=b)
        {
            char c = s[a];
            s[a] = s[b];
            s[b] = c;
        }
    }
public:
    int longestStrChain(vector<string>& words) {
        int result=1;
        sort(words.begin(),words.end(),[](string &a, string &b){return a.size()<b.size();});
        int len = words.size();
        vector<int> dp(len,1);
        int currlen = -2;
        int preLen = -1;
        int preS=-2,preE=-2;
        for(int i=0;i<len;i++)
        {
            if(currlen != words[i].size())
            {
                
                preLen = currlen;
                preS = preE+1;
                preE = i-1;
                currlen = words[i].size();
                //cout<<"prelen="<<preLen<<" currlen="<<currlen<<" =["<<preS<<","<<preE<<"]"<<endl;
                // search current word in previous list
                if(preLen == currlen-1)
                {
                    string ss = words[i];
                    
                    for(int j=0;j<currlen;j++)
                    {
                        swap(ss,j,0);
                        
                        for(int k=preS;k<=preE;k++)
                        {
                            if(ss.substr(1,preLen)== words[k])
                            {
                                //cout<<"ss="<<ss.substr(1,preLen)<<" w="<<words[k]<<endl;
                                dp[i] = max(dp[i],dp[k]+1);
                                result = max(dp[i],result);
                            }
                        }
                    }
                }
            }
            else
            {
                if(preLen == currlen-1)
                {
                    string ss = words[i];
                    
                    for(int j=0;j<currlen;j++)
                    {
                        swap(ss,j,0);
                        
                        for(int k=preS;k<=preE;k++)
                        {
                            if(ss.substr(1,preLen)== words[k])
                            {
                                //cout<<"ss="<<ss.substr(1,preLen)<<" w="<<words[k]<<endl;
                                dp[i] = max(dp[i],dp[k]+1);
                                result = max(dp[i],result);
                            }
                        }
                    }
                }
            }
            
        }
        return result;
    }
};
