/*
Leetcode

 problem- Remove All Adjacent Duplicates in String II

Link - https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3710/

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
    string removeDuplicates(string s, int k) {
        typedef pair<char,int> item;
        string result;
        deque<item> myStack;
        item currItem={' ', 0 };
        for(int i=0;i<s.size();i++)
        {
            if(!myStack.empty())
            {
                item& t=myStack.back();
                //cout
                if(t.first==s[i])
                {
                    ++(t.second);
                    if(t.second==k)
                        myStack.pop_back();
                }
                else
                {
                    currItem.first = s[i];
                    currItem.second = 1;
                    myStack.push_back(currItem);
                }
            }
            else
            {
                currItem.first = s[i];
                currItem.second = 1;
                myStack.push_back(currItem);
            }
        }
        
        // convert dequeue to string
        for(item it:myStack)
        {
            result.append(it.second,it.first);
        }
        
        return result;
    }
};
