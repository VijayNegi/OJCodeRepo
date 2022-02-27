/*
Leetcode

problem- Find Duplicate File in System

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3747/

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
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> hashmap;
        
        for(int i=0;i<paths.size();i++)
        {
            auto pathEnd = paths[i].find(" ");
            string path = paths[i].substr(0,pathEnd);
            //cout<<"Path-"<<path<<endl;
            auto posS = pathEnd;
            auto posE = pathEnd;
            while(true)
            {
                posE = paths[i].find("(", posS-1);
                if(posE == string::npos)
                    break;
                //cout<<" posS-"<<posS<< " posE-"<<posE<<endl;
                string file = paths[i].substr(posS+1,posE - posS-1);
                posS = posE;
                posE = paths[i].find(")" ,posS );
                string content = paths[i].substr(posS+1,posE -posS-1);
                
                //cout<<"content- "<<content<<endl;
                //cout<<"file- "<<file<<endl;
                hashmap[content].push_back(path+"/"+file);
                posS = posE+1;
            }
        }
        
        //cout<<" map entries:"<<endl;
        for(auto c:hashmap)
        {
            //cout<<c.first<<" ";
//             vector<string> samc;
//             for(auto& k:c.second)
//             {
//                 //cout<<k<<" ";
//                 samc.push_back(k);
                
//             }
            if(c.second.size()>1)
                result.push_back(std::move(c.second));
            //cout<<endl;
        }
        
        return result;
    }
};
