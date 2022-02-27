/*
Leetcode

 problem-     Clone Graph

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3501/

tags - bfs

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
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> _map;
    Node* helper(Node* head)
    {
        if(head==NULL)
            return NULL;
        
        auto node = _map.find(head->val);
        if(node!= _map.end())
            return node->second;
        
        Node* copy = new Node(head->val);
        //fill map
        _map[copy->val]= copy;
        //fill neighbors vectors
        vector<Node*>& nb = head->neighbors;
        
        for(auto a : nb)
        {
            copy->neighbors.push_back(helper(a));
        }

        return copy;
    }
public:
    Node* cloneGraph(Node* node) {
        _map.clear();
        return helper(node);
    }
};
