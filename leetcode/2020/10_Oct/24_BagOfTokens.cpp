/*
Leetcode

 problem-     Bag of Tokens

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3506/

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
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        if (tokens.size() == 0 || P < tokens[0]) return 0;
        int left=0;
        int right = tokens.size()-1;
        int score=0;
        while(left<=right)
        {
            while(left<=right)
            {
                if(tokens[left]<=P) // buy all low priced
                {
                    P-=tokens[left];
                    ++left;
                    ++score;
                    //cout<<score<<endl;
                }
                else
                    break;
            }
            
            if(left<(right-1)) // buy one max
            {
                P+=tokens[right];
                --right;
                --score;
                //cout<<score<<endl;
            }
            else
                break;
        }
        
        return score;
    }
};
