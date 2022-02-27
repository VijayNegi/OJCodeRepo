/*
Leetcode

 problem-     Convert Binary Number in a Linked List to Integer

Link - https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3516/

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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int bin[30];
        int len=0;
        ListNode* currNode = head;
        while(currNode)
        {
            bin[len++]=currNode->val;
            currNode = currNode->next;
        }
        if(len == 0)
            return 0;
        
        int result = 0;
        int pow=1;
        while(len>0)
        {
            --len;
            if(bin[len])
                result +=pow;
            pow*=2;
        }
        
        return result;
    }
};
