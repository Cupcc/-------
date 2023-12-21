/**
 * @Date: 2023 Dec 21
 * @Time: 08:15
 * @Author: Chris
 * @Title: 518. Coin Change II
 * @Link: https://leetcode.cn/problems/coin-change-ii/description/
 **/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  // the combination number
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1);
    dp[0] = 1; //测试样例得出，dp[1] = dp[1] + dp[0]
    for (int coin : coins) {
      // 完全背包可重复，从0开始，其实从j-coin >=0开始
      for (int j = coin; j <= amount; ++j) {
        dp[j] += dp[j - coin];
      }
    }
    return dp[amount];
  }
};
int main() { return 0; }