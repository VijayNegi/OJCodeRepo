/*
Leetcode
problem-   LRU Cache
Link - https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3309/
        
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
#include <deque>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;



class LRUCache {
public:
    int _maxCap;
    deque<unordered_map<int,int>::iterator> _queue;
    unordered_map<int,int> _map;
    LRUCache(int capacity) {
        _maxCap = capacity;
        _map.reserve(capacity+1); // be on safe side
    }
    
    int get(int key) {
        auto search = _map.find(key);
        if (search != _map.end()) {
            //move it to front of queue
            auto itr = _queue.begin();
            auto end = _queue.end();
            while (true)
            {
                if(*itr==search)
                {
                    _queue.erase(itr);
                    _queue.push_front(search);
                    break;
                } 
                itr++;
            }
            return search->second;
        } 
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // check if it is already there
        auto search = _map.find(key);
        if (search != _map.end()) {
            //move it to front of queue
            auto itr = _queue.begin();
            auto end = _queue.end();
            while (true)
            {
                if(*itr==search)
                {
                    _queue.erase(itr);
                    _queue.push_front(search);
                    break;
                } 
                itr++;
            }
            //update the value
            search->second = value;
            return;
        } 
        //remove if in excess
        if(_queue.size()>=_maxCap){
            //remove from queue
            auto last = _queue.back();
            _queue.pop_back();
            //remove from map
            _map.erase(last);
        }
        
        auto itr = _map.insert({key,value});
        _queue.push_front(itr.first);
    }
};

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
    // Solution *obj = new Solution();
    // //vector<vector<int>> myVec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    // vector<int> myVec = {8,5,1,7,10,12};
    // string str = "((()))*";
    // auto ans = obj->rangeBitwiseAnd(5,7);
    // cout << "\n ans -> " << ans;
    LRUCache cache( 2 /* capacity */ );
    cache.put(1, 1);
    cout<<"\ncache.put(1, 1) ";
    cache.put(2, 2);
    cout<<"\ncache.put(2, 2) ";
    cout<<"\ncache.get(1) -> "<<cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout<<"\ncache.put(3, 3)";
    cout<<"\ncache.get(2) -> "<<cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout<<"\ncache.put(4, 4) ";
    cout<<"\ncache.get(1) -> "<<cache.get(1);       // returns -1 (not found)
    cout<<"\ncache.get(3) -> "<<cache.get(3);       // returns 3
    cout<<"\ncache.get(4) -> "<<cache.get(4);       // returns 4
  
    return 0;
}