/*
Leetcode

problem- Reverse Linked List II

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3789/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode dummy(0,head);

        ListNode* firstSeg=nullptr;
        ListNode* rev = nullptr;
        
        firstSeg = &dummy;
        int i=1;
        while(firstSeg && i<left)
        {
            firstSeg = firstSeg->next;
            ++i;
        }
        rev = firstSeg->next;
        ListNode* ptr = nullptr;
        while(i<right)
        {
            ++i;
            ptr = rev->next;
            rev->next = ptr->next;
            ptr->next = firstSeg->next;
            firstSeg->next = ptr;
        }
        
        return dummy.next;
    }
};
