/*
Leetcode
 problem-     Sort List

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3493/

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
    ListNode* mergesort(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        //cout<<"head-"<<head->val<<endl;
        ListNode* fst;
        ListNode* slw;
        fst = slw =head;
        //slw=head;
        while(fst->next && fst->next->next)
        {
            slw = slw->next;
            fst = fst->next->next;
        }
        
        if(fst==slw) // only one or two in list
        {
            if(!slw->next)
                return slw;
            else
            {
                fst = fst-> next;
                if(slw->val > fst->val)
                {
                    int temp = slw->val;
                    slw->val = fst->val;
                    fst->val = temp;
                }
                return slw;
            }
        }
        //else
        //{
            ListNode* temp = slw;
            
            slw = slw->next;
            temp->next = NULL;
            ListNode* list1 = mergesort(head);
            ListNode* list2 = mergesort(slw);
        //}
        ListNode* newHead;
        
        if(list1->val > list2->val)
        {
            newHead = list2;
            list2 = list2->next;
        }
        else
        {
            newHead = list1;
            list1 = list1->next;
        }
        ListNode* curr = newHead;
        while(list1 && list2)
        {
            if(list1->val > list2->val)
            {
                curr->next = list2;
                list2 = list2->next;
            }
            else
            {
                curr->next = list1;
                list1 = list1->next;
            }
            curr = curr->next;
        }
        while(list1)
        {
            curr->next = list1;
            curr = curr->next;
            list1 = list1->next;
        }
        
        while(list2)
        {
            curr->next = list2;
            curr = curr->next;
            list2 = list2->next;
        }
            
        return newHead;
        
    }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};
