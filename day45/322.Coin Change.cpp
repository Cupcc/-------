/**
 * @Date: 2023 Dec 22
 * @Time: 15:54
 * @Author: Chris
 * @Title: 322.Coin Change
 * @Link: https://leetcode.cn/problems/coin-change/description/
 **/
#include <_types/_intmax_t.h>

#include <iostream>
#include <vector>

using namespace std;
/// 含义dp[j] 凑足金钱为j的所需最少的硬币个数
//  状态转移 dp[j] = min(dp[j], dp[j-coin] + 1)
//  初始化 dp[0]=0, 其他的都为最大的数字。
//  遍历顺序，物品无限制，从前向后
class Solution {
 public:
  // 注意返回值的细节，注意溢出的处理，注意初始化的处理
  int coinChange(vector<int>& coins, int amount) {
    // amount + 1 为可行的最大值
    // 为什么不是amount  因为 amount 可以为0，当为0,测试答案的结果为0，而不是-1。
    int MAX = amount + 1;
    vector<int> dp(amount + 1, MAX);
    dp[0] = 0;
    for (int coin : coins) {
      for (int j = coin; j <= amount; ++j) {
        dp[j] = min(dp[j], dp[j - coin] + 1);
      }
    }
    return dp[amount] == MAX ? -1 : dp[amount];
  }
};
int main() { return 0; }