/*
Leetcode

problem- Prefix and Suffix Search

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/

tags - Trie, HashMap
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

#define TRIE_LEN 27
class Trie{
    public:
    int highestId;
    Trie* next[TRIE_LEN];
    
    Trie()
    {
       fill(next, next+TRIE_LEN, nullptr);
        highestId=0;
    }
    ~Trie()
    {
        for(int i=0;i<TRIE_LEN;i++)
        {
            if(next[i])
                delete next[i];
        }
    }
    void insert(string& word,int pos,int id)
    {
        highestId = id;
        if(pos < word.size())
        {
            int ch = word[pos]- 'a';
            if(!next[ch])
                next[ch] = new Trie();
            next[ch]->insert(word,pos+1,id);
        }
    }
    int search(string& word, int pos)
    {
        if(pos == word.size())
        {
            return highestId;
        }
        else
        {
            if(!next[word[pos]- 'a'])
            {
                return -1;
            }
            else
                return next[word[pos]- 'a']->search(word,pos+1);
        }
            
    }
        
};

class WordFilter {
    Trie TrieRoot;
public:
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            int len = words[i].size();
            for(int k=0;k<=len;k++)
            {
                string suff = words[i].substr(k,len);
                string str = suff+"{"+ words[i];
                TrieRoot.insert(str,0,i);
            }
        }
        
    }
    
    int f(string prefix, string suffix) {
        string str = suffix+"{"+prefix;
        return TrieRoot.search(str,0);
    }
};

////======== hashMap solution
/*
class WordFilter {
    unordered_map<string,int> hashmap;
public:
    WordFilter(vector<string>& words) {
        
        for(int i=0;i<words.size();i++)
        {
            int len = words[i].size();
            for(int k=0;k<=len;k++)
            {
                string pre = words[i].substr(0,k);
                for(int l=0;l<len;l++)
                {
                    string suff = words[i].substr(l,len);
                    hashmap[pre+"|"+suff] = i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return hashmap[prefix+"|"+suffix] - 1;
    }
};

*/

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
