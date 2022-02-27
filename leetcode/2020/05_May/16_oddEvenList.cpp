/*
Leetcode
problem-   Odd Even Linked List
Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3331/
        
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
#include <map>
#include <list>
#include <utility>
#include <deque>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;



//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *first,*second,*current,*second2;
        if(head==NULL || head->next==NULL || head->next->next == NULL)
            return head;
        first = head;
        second = head->next;
        current = second->next;
        second2 = second;
        bool beven = true;
        while(current!=NULL)
        {
            if(beven)
            {
                first->next=current;
                first = first->next;
            }
            else
            {
                second2->next=current;
                second2 = second2->next;
            }
            current = current->next;
            beven = !beven;
            
        }
        first->next = second;
        second2->next = NULL;
        return head;
    }
};
/*
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // disable buffering on stdout completely
    setbuf(stdout, NULL);
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

#endif
     Solution *obj = new Solution(); 
    vector<vector<int>> myVec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<char>> myVecChar = {{'1','0','1','0','0'},
                                        {'1','0','1','1','1'},
                                        {'1','1','1','1','1'},
                                        {'1','0','0','1','0'}};
                   
                                      
    //vector<int> myVec = {2,3,1,1,4};
    // string str = "((()))*";
    map<pair<string, int>,string> testCases{ {{"12345",1},"1234"},
                           {{"12315",1},"1215"},
                            {{"171819",2},"1119"},
                            {{"123234345",1},"12234345"},
                            {{"1200456",3},"45"},
                            {{"123456",3},"123"}
                                            };

    for(auto test:testCases)
    {
        //vector<int>& cvec = const_cast<vector<int>&>(test.first);
        auto ans = obj->removeKdigits(test.first.first,test.first.second);

        cout << "\n ans -> " << ans << " | expected->"<< test.second;
    }
    
    
  
    return 0;
}
*/