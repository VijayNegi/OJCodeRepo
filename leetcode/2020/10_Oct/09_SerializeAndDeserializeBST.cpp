/*
Leetcode
 problem-     Serialize and Deserialize BST

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3489/
        
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    TreeNode* build(vector<int>& data,int l, int r)
    {
        //cout<<"l- "<<l<<" ,r- "<<r<<endl;
        if(l>r)
            return NULL;
        if(l==r)
        {
            return new TreeNode(data[l]);
        }
        int m=l;
        for(int i = l+1; i <= r; i++)
        {
            if(data[i]>data[l])
                break;
            m++;
        }
        TreeNode* root = new TreeNode(data[l]);
        root->left = build(data,l+1,m);
        root->right = build(data,m+1,r);
        return root;
    }
    
    void buildPreorder(TreeNode* root, vector<int>& pre)
    {
        if(root == NULL)
            return;
        
        pre.push_back(root->val);
        
        if(root->left)
            buildPreorder(root->left,pre);
        if(root->right)
            buildPreorder(root->right,pre);
        
        return ;
    }
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root == NULL)
            return "";
        
        vector<int> pre;
        buildPreorder(root, pre);
        
        string result;
        result += to_string(pre[0]);
        for(int i=1;i<pre.size();i++)
        {
            result += ","+ to_string(pre[i]);
        }
        //cout<< "s - "<< result<<endl;
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> nodes;
        
        std::size_t current, previous = 0;
        string delim(",");
        current = data.find(delim);
        while(current != std::string::npos)
        {
            string num = data.substr(previous, current - previous  );
            //cout<<" num - "<<num<<endl;
            nodes.push_back(std::stoi(num));
            previous = current + 1;
            current = data.find(delim, previous);
        }
        // add last
        string num = data.substr(previous, data.size() - previous  );
        if(num.size())
            nodes.push_back(std::stoi(num));
        TreeNode* root = NULL;
        //cout<<" nsize - "<< nodes.size()<<endl;
        if(nodes.size())
           root = build(nodes, 0, nodes.size() - 1);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
