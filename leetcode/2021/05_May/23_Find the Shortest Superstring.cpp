/*
Leetcode

problem- Find the Shortest Superstring

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3753/

tags - HARD , copied code
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
  string shortestSuperstring(vector<string>& A) {
    const int n = A.size();
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        g[i][j] = A[j].length();
        for (int k = 1; k <= min(A[i].length(), A[j].length()); ++k)
          if (A[i].substr(A[i].size() - k) == A[j].substr(0, k))
            g[i][j] = A[j].length() - k;
      }
    
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));
    
    for (int i = 0; i < n; ++i) dp[1 << i][i] = A[i].length();
    
    for (int s = 1; s < (1 << n); ++s) {
      for (int j = 0; j < n; ++j) {
        if (!(s & (1 << j))) continue;
        int ps = s & ~(1 << j);
        for (int i = 0; i < n; ++i) {
          if (dp[ps][i] + g[i][j] < dp[s][j]) {
            dp[s][j] = dp[ps][i] + g[i][j];
            parent[s][j] = i;
          }
        }
      }
    }
    
    auto it = min_element(begin(dp.back()), end(dp.back()));
    int j = it - begin(dp.back());
    int s = (1 << n) - 1;
    string ans;
    while (s) {
      int i = parent[s][j];
      if (i < 0) ans = A[j] + ans;
      else ans = A[j].substr(A[j].length() - g[i][j]) + ans;
      s &= ~(1 << j);
      j = i;
    }
    return ans;
  }
};
