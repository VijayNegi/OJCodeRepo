/*
Leetcode
problem-    Permutation in String
Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3333/
        
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
    vector<int> findAnagrams(string s, string p) {
    map<char,int> org;
    int plen = p.length();
    int slen = s.length();
    for(char c:p)
    {
        org[c]++;
    }        
    list<map<char,int>> curr;
    vector<int> ans;
    
    // now check main string
    for(int i=0;i< s.length();i++)
    {
        char c = s[i];
        if(org.count(c)>0) // if char is availabe then check current list and add new
        {
            auto it = curr.begin();
            while(it!=curr.end())
            {
                if(it->count(c)>0)
                {
                    (*it)[c]--;
                    //cout<<"map - "<<c<<" - "<<(*it).count(c)<<" "<<(*it)[c]<<endl;
                    if((*it)[c]==0)
                         it->erase(c);
                    // if map becomes empty then its anagram
                    if(it->empty())
                        ans.push_back(i-plen+1);

                    it++;
                    
                }
                else
                {
                    it = curr.erase(it); // if not there then not an anagram
                }
                
            }
            // add new anagram start if it can complete
            if(i+plen <= slen)
            {
                map<char,int> temp = org;
                temp[c]--;
                if(temp[c]==0)
                    temp.erase(c);
                if(temp.empty())
                    ans.push_back(i-plen+1);
                else
                    curr.push_back(temp);
            }
            
        }
        else // clear all list, none can be anagram
        {
            curr.clear();
        }
    }
    return ans;
    }
    bool findAnagrams1(string s, string p) {
        int org[26]={0};
        int running[26]={0};
        size_t size = sizeof(org);
        int plen = p.length();
        int slen = s.length();
        //vector<int> ans;
        if(plen>slen)
            return false;
        for(char c:p)
        {
            org[c-'a']++;
        }  
        for (size_t i = 0; i < plen; i++)
        {
            running[s[i]-'a']++;
        }
        int cmp = memcmp(org,running,size);
        if(cmp==0)
            return true;
        for (size_t i = plen; i < slen; i++)
        {
            running[s[i]-'a']++;
            running[s[i-plen]-'a']--;
            int cmp = memcmp(org,running,size);
            if(cmp==0)
                return true;
        }
        return false;

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
    map<pair<string, string>,vector<int>> testCases{ {{"abab","ab"},{0,1,2}},
                                                    {{"cbaebabacd","abc"},{0,6}},
                                                    {{"aaaaaaaaa","aa"},{0,1,2,3,4,5,6,7}},
                                                    {{"afdkljflsdkjfsdlkjfdslkjfdslkjfkljlkjlkfdjslkfjsdlkjsdflksdjflkdsjfldskjksldfjlksdjflkdsjfsjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjfsdfaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","z"},{}}
                          
                                            };

    for(auto test:testCases)
    {
        //vector<int>& cvec = const_cast<vector<int>&>(test.first);
        auto ans = obj->findAnagrams1(test.first.first,test.first.second);

        std::ostream_iterator<int> out_it(std::cout,", ");
        
        cout << "\n ans -> "<<ans; 
        //std::copy(ans.begin(), ans.end(), out_it);
        cout << " | expected-> ";
       // std::copy(test.second.begin(), test.second.end(), out_it);
    }
    
    
  
    return 0;
}