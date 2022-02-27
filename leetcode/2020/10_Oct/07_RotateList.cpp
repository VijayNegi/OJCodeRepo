/*
Leetcode
 problem-     Rotate List

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3486/
        
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
     ListNode* rotateRight(ListNode* head, int k) {
         int len=0;
         ListNode* NewHead = head;
         ListNode* start = head;
         if(head == NULL || k == 0)
             return head;
         
         while(start->next != NULL )
         {
             if(len>=k)
                 NewHead = NewHead->next;
             len++;
             start = start->next;
         }
         len++; // last node
         
         if(k==len)
             return head;
         
         if(k<=len)
         {
             start->next = head;
             head = NewHead->next;
             NewHead->next = NULL;
         }
         else
         {
             int m = k%(len);
             m = len - m;
             NewHead = head;
             while(--m)
             {
                 NewHead = NewHead->next;
             }
             
             start->next = head;
             head = NewHead->next;
             NewHead->next = NULL;
         }
         
         return head;
     }
 };
