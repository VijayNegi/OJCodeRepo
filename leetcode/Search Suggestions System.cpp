/*
Leetcode
problem-   Search Suggestions System
Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/602/week-5-may-29th-may-31st/3762/
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
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
using namespace std;

#define TRIE_LEN 26
struct Trie
{
    public:
    vector<int> ProductID;
    //bool end;
    Trie* next[TRIE_LEN];
    
    Trie()
    {
        fill(next,next+TRIE_LEN,nullptr);
        //end = false;
            
    }
    ~Trie()
    {
        for(int i=0;i<TRIE_LEN;++i)
        {
            if(next[i])
                delete next[i];
        }
    }
    
    void search(string s,int index, vector<vector<int>> & result)
    {
        cout<<" search-"<<s<<" "<<index<<endl;
        if(index<=s.size()-1)
        {
            cout<<" product size-"<<ProductID.size()<<"->"<<s<<" "<<endl;
            //if(result.size())
            if(ProductID.size()==1)
            {
                    result.back().push_back(ProductID[0]);
            }
            else
            {
                
                
                for(int i=0;i<TRIE_LEN;++i)
                {
                    
                    if(next[i])
                    {
                        cout<<"1->"<<'a'+i<<endl;
                        next[i]->search(s,s.size()-1,result);
                    }
                    
                    if(!result.empty() && result.back().size()>2)
                        break;
                    //cout<<"3 - size"<<result.back().size()<<endl;
                }
            }
        }
        if(index < s.size()-1)
        {
            cout<<"2"<<endl;
            result.push_back({});
            cout<<" product size-"<<ProductID.size()<<"->"<<s<<" "<<endl;
            if(ProductID.size()==1)
                    result.back().push_back(ProductID[0]);
            else
            {
                if(next[s[index]-'a'])
                    next[s[index]-'a']->search(s,index+1, result);
            }   
        }
        
        return;
        
    }
    void insert(string s,int index,int pID)
    {
        if(index>=s.size())
            return;
        cout<<" insert-"<<s<<" "<<index<<" "<<pID<<endl;
        next[s[index]-'a'] = new Trie();
        //next[s[index]-'a']->ProductID.push_back(pID);
        ProductID.push_back(pID);
        next[s[index]-'a']->insert(s,index+1,pID);
        
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie root;
        for(int i=0;i<products.size();++i)
        {
            root.insert(products[i],0,i);
        }
        
        vector<vector<int>> res;
        res.push_back({});
        root.search(searchWord,0,res);
        vector<vector<string>> result;
        
        //if(!result.empty() )
            //cout<<"3 - sizeqqqq"<<result.size()<<endl;
        for(int i=0;i<res.size();++i)
        {
            result.push_back({});
            for(int j=0;j<res[i].size();++j)
            {
                cout<<","<<products[res[i][j]];
                result.back().push_back(products[res[i][j]]);
            }
            cout<<endl;
        }
        return result;
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
    std::vector<std::string> myVec = {"mobile","mouse","moneypot","monitor","mousepad"};


    string str = "abcdef";
    auto ans = obj->suggestedProducts(myVec,"mobile");

    for(auto n:ans)
        {
            
            for(auto k:n)
            {
                cout<<k<<" -> ";
            }
            cout<<std::endl;
        }
    return 0;
}