/**
 * @Date: 2023 Dec 27
 * @Time: 23:46
 * @Author: Chris
 * @Title: 70. Climbing Stairs
 * @Link: https://leetcode.cn/problems/climbing-stairs/description/
 **/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    int first = 1;
    int second = 2;
    if (n <= 2) return n;
    for (int i = 3; i <= n; ++i) {
      // 第i个台阶方法数 = 第i-1方法数 + i-2方法数
      int tmp = first + second;
      // 更新
      first = second;
      second = tmp;
    }
    return second;
  }
  int climbStairs2(int n) {
    if (n < 3) return n;
    vector<int> dp(n + 2, 0);
    // 方便计数，规定的
    dp[0] = 1;
    // dp[i] 为上到第i个台阶的方法数
    for (int i = 0; i < n; ++i) {
      // 从前向后推导
      // 走一步
      dp[i + 1] += dp[i];
      // 走两步
      dp[i + 2] += dp[i];
    }
    // 注意是第n个台阶
    return dp[n];
  }
};
int main() { return 0; }