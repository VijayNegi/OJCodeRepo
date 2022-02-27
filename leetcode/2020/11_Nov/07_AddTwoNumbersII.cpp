/*
Leetcode

 problem-     Add Two Numbers II

Link - https://leetcode.com/explore/featured/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3522/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> N1,N2,N3;
        ListNode* curr;
        ListNode* result=NULL;
        curr = l1;
        while(curr)
        {
            N1.push_back(curr->val);
            curr=curr->next;
        }
        curr = l2;
        while(curr)
        {
            N2.push_back(curr->val);
            curr=curr->next;
        }
        int carry=0;
        int i1,i2;
        i1=N1.size()-1;
        i2=N2.size()-1;
        while(true)
        {
            if(i1>=0)
            {
                carry+=N1[i1];
                --i1;
            }
            if(i2>=0)
            {
                carry+=N2[i2];
                --i2;
            }
            ListNode* temp = new ListNode(carry%10,result);
            carry/=10;
            result = temp;
            if(i1<0 && i2<0)
                break;
        }
        if(carry)
        {
            ListNode* temp = new ListNode(carry,result);
            //carry/=10;
            result = temp;
        }
        return result;
    }
};
