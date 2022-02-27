/*
Leetcode

problem- Reverse Nodes in k-Group

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3818/

tags - Hard
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while(curr)
        {
            ++n;
            curr = curr->next;
        }
        int t = n/k;
        if(t==0 || k<2 || n==1)
            return head;
        
        ListNode Dummy(0,head);
        ListNode* start = &Dummy;
        curr = head;
        for(int i=0;i<t;++i)
        {
            int kk = k;
            while(--kk >0)
            {
                ListNode* tail = start->next;
                start->next = curr->next;
                curr->next = start->next->next;
                start->next->next = tail;
            }
            start = curr;
            curr = start->next;
        }
        
        return Dummy.next;
    }
};
