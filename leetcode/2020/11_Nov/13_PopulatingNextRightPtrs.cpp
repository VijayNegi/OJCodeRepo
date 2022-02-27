/*
Leetcode

 problem-     Populating Next Right Pointers in Each Node

Link - https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3529/

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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* connect(Node* root) {
        
        if(!root || !(root->left))
            return root;
        Node* CurrParents = root;
        Node* NextParents = root->left;
        //if(!NextParents)
        
        while(NextParents)
        {
            CurrParents->left->next = CurrParents->right;
            if(CurrParents->next)
                CurrParents->right->next = CurrParents->next->left;
            
            CurrParents = CurrParents->next;
            if(!CurrParents)
            {
                CurrParents = NextParents;
                NextParents = CurrParents->left;
            }
        }
        
        return root;
    }
};
