/*
Leetcode

problem- Super Palindromes

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3736/

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

typedef long long ll;
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        int ans=0;
        ll l = stol(left);
        ll r = stol(right);
        //ll num=0;
        ll sqrt_l = sqrt(l), sqrt_r = sqrt(r), num=0;
        for(int i=1;num<=sqrt_r;i++)
        {
            num = createPalindrome(i,i);
            
            if(num>=sqrt_l && num<=sqrt_r && isPalindrome((num*num)))
                ans++;
            num = createPalindrome(i,i/10);
           
            if(num>=sqrt_l && num<=sqrt_r && isPalindrome((num*num)))
                ans++;
        }
        return ans;
    }
    
private:
    int createPalindrome(ll prefix,ll suffix)
    {
        while(suffix>0)
        {
            prefix = prefix*10 + suffix%10;
            suffix/=10;
        }
        return prefix;
    }
    bool isPalindrome(ll num)
    {

        ll rev=0, temp=num;
        while(temp>0){
            rev=rev*10+temp%10;
            temp/=10;
        }
        return rev==num;
    }
};
