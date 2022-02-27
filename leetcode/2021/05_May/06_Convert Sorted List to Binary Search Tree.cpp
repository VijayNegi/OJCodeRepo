/*
Leetcode

problem- Convert Sorted List to Binary Search Tree

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3733/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* vec2Tree(vector<int>& vec, int begin,int end)
    {
        if(end<begin)
            return NULL;
        if(begin==end)
            return new TreeNode(vec[begin]);
        int mid = begin+(end-begin)/2;
        
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = vec2Tree(vec,begin,mid-1);
        root->right = vec2Tree(vec,mid+1,end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vlist;
        TreeNode* result=NULL;
        ListNode* curr= head;
        while(curr)
        {
            vlist.push_back(curr->val);
            curr=curr->next;
        }
        if(vlist.size()<1)
            return result;
        
        result = vec2Tree(vlist,0,vlist.size()-1);
        return result;
        
    }
};
