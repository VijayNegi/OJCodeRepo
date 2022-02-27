/*
Leetcode

 problem-     Asteroid Collision

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3502/

tags - stack

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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int len = asteroids.size();
        vector<int> stack;
        stack.reserve(len);
        vector<int> result;
        result.reserve(len);
        for(int i=0;i<len;i++)
        {
            
            if(asteroids[i]>0) // keep track of asteroids moving right as we are moving right
                stack.push_back(asteroids[i]);
            else // if asteroid is moving left check if it has anything to collide with
            {
                int moveLeft = abs(asteroids[i]);
                //cout<<" -- "<<asteroids[i]<<endl;
                while(true)
                {
                    if(stack.empty()) // nothing to collide
                    {
                        result.push_back(asteroids[i]); // push to result;
                        break;
                    }
                    if(stack.back() > moveLeft) // this one gets destroid
                        break;
                    else if(stack.back() ==  moveLeft)
                    {
                        stack.pop_back();
                        break;
                    }
                    if(stack.back() < moveLeft)
                        stack.pop_back();
                }
                
            }
        }
        result.insert(result.end(),stack.begin(),stack.end());
        return result;
    }
};
