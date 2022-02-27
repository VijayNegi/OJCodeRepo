/*
Leetcode
problem-   Iterator for Combination
Link - https://leetcode.com/problems/iterator-for-combination/
        
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
#include <deque>
#include <map>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;


class CombinationIterator {
public:
    string _chars;
    int comLength;
    bool _bNext;
    int strLen;
    string _next;
    vector<int> _pos;
    int _digit;
    CombinationIterator(string characters, int combinationLength) {
        _chars = characters;
        strLen = _chars.size();
        comLength = combinationLength;
        _bNext = false;
        _next = _chars;
        _pos.resize(comLength);
        _digit = comLength-1;
        std::iota (std::begin(_pos), std::end(_pos), 0); // Fill with 0, 1, ..., 99.
        if(strLen >= comLength)
        {
            _bNext = true;
            formString(_chars,_pos,_next);
        }
        
    }
    
    string next() {
        string temp = _next;
        
        _digit=comLength-1;
        bool reset = false;
        while(_digit>=0)
        {
            if(_pos[_digit]<(strLen - comLength  +_digit ))
            {
                _pos[_digit]++;
                if(reset)
                    std::iota (std::begin(_pos)+_digit+1, std::end(_pos), _pos[_digit]+1);
                break;
            }
            else
            {
                //if(_pos[_digit-1]<(strLen-_digit-1))
                //    _pos[_digit] = _pos[_digit-1]+2;
                reset = true;
                _digit--;
            }
        }
        if(_digit>=0)
        {
            _bNext = true;
            formString(_chars,_pos,_next);
        }
        else
        {
            _bNext = false;
        }
        
        return temp;
    }
    
    bool hasNext() {
        return _bNext;
    }
    
    bool formString(string src,vector<int>& pos,string &out)
    {
        bool ret(true);
        //for(int i=0;i<pos.size();i++)
        out.clear();
        out.reserve(pos.size());
        for(int p: pos)
        {
            out.push_back(src[p]);
        }
        
        return ret;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

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
     //Solution *obj = new Solution(); 
    //vector<vector<int>> myVec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    /* map<vector<vector<int>>,int> testCases{ 
                           {{   {1,1,1},
                                {1,1,1},
                                {1,1,1}}, 14},
                           {{   {0,1,1},
                                {1,1,1},
                                {1,1,1}}, 11},
                            {{   {0,1,0},
                                 {1,0,1},
                                 {0,1,0}}, 4}
                           
                                            };
    */
    // for(auto test:testCases)
    // {
    //     //vector<int>& cvec = const_cast<vector<int>&>(test.first);
    //     auto ans = obj->countSquares(const_cast<vector<vector<int>>&>(test.first));

    //     cout << "\n ans -> " << ans << " | expected->"<< test.second;
    // }
    string characters = "abc";
    int combinationLength = 2;
    CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
    bool flag = true;
    while(flag)
    {
    string str = obj->next();
    cout<<str<<endl;
    flag = obj->hasNext();
    }

  
    return 0;
}