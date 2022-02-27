/*
Leetcode

 problem-     Insertion Sort List

Link - https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3517/

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
    ListNode* insertsort(ListNode* sorted,ListNode* node)
    {
        if(sorted->val > node->val)
        {
            node->next = sorted;
            return node;
        }
        ListNode* currNode = sorted;
        while(currNode->next)
        {
            if(currNode->next->val > node->val)
                break;
            else
                currNode = currNode->next;
        }
        
        ListNode* temp = currNode->next;
        currNode->next = node;
        node->next = temp;
        return sorted;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
            return head;
 
        ListNode* currNode = head->next;
        ListNode* newList = head;
        newList->next = NULL;
        while(currNode)
        {
            ListNode* temp = currNode;
            currNode = currNode->next;
            newList = insertsort(newList, temp);
        }
        return newList;
    }
};
