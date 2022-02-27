/*
Leetcode
problem-   Valid Parenthesis String
Link - https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3301/
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
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
using namespace std;

class Solution {
public:

    bool checkValidString(string s) {
        list<int>  openb,closeb,ast;
        for(int i=0;i<s.length();i++)
        {
            switch (s[i])
            {
            case '(':
                openb.push_back(i);
                break;
            case ')':
                closeb.push_back(i);
                break;
            case '*':
                ast.push_back(i);
                break;
            default:
                break;
            }
        }

        int olen = openb.size();
        int clen = closeb.size();
        int alen = ast.size();

        //if there is no way they can match
        if(abs(olen-clen)>alen)
            return false;

        int oitr = openb.back();
        auto citr = closeb.begin();

        //search for appropriate ) for every ( from the end of list, if not found 
        //search in * list . keep location in mind
        bool match_found = false;
        for(int i=0;i<olen;i++)
        {
            int opos = openb.back();
            openb.pop_back();
            citr = closeb.begin();
            match_found = false;
            while(citr!=closeb.end())
            {
                if(*citr>opos) // match found
                {
                    match_found=true;
                    closeb.erase(citr);
                    break;
                }
                citr++;
            }
            if(match_found==false)
            {
                auto aitr = ast.begin();
                while(aitr!=ast.end())
                {
                    if(*aitr>opos) // match found
                    {
                        match_found=true;
                        ast.erase(aitr);
                        break;
                    }
                    aitr++;
                }
            }
            if(match_found==false)
                return false;
        }
        if(closeb.size()>0) // match ) with *
        {
            clen = closeb.size();
            for(int i=0;i<clen;i++)
            {
                match_found = false;
                int cpos = closeb.front();
                closeb.pop_front();
                auto aitr = ast.begin();
                while(aitr!=ast.end())
                {
                    if(*aitr<cpos) // match found
                    {
                        match_found=true;
                        ast.erase(aitr);
                        break;
                    }
                    aitr++;
                }
                if(match_found==false)
                    return false;
            }
        }
            
        return true;
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
    Solution* obj = new Solution();
    //std::vector<int> myVec = {2,2,2,2};
    string str = "((()))*";
    auto ans = obj->checkValidString(str);
    cout<<"\n ans -> "<<ans;
    
    return 0;
}