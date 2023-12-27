/**
 * @Date: 2023 Dec 27
 * @Time: 22:17
 * @Author: Chris
 * @Title: 188. Best Time to Buy and Sell Stock IV
 * @Link:
 *https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
 **/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
    // 奇数买入，减去第一天股票价格
    for (int j = 1; j < 2 * k + 1; j += 2) {
      dp[0][j] = -prices[0];
    }
    // j = 0. 无操作，值为0，便于统一第一次买入操作
    //   = 1. 第一次持有
    //   = 2. 第一次不持有
    //   = 3. 第二次持有
    //   = 4. 第二次不持有
    //   = 5................
    // 从第二天开始
    for (int i = 1; i < prices.size(); ++i) {
      // 从j=1开始 1,2; 3,4; 5,6操作。
      for (int j = 1; j < 2 * k; j += 2) {
        // 第i天持有 = i-1天不持有，今日买入 ｜ 保持i-1天的持有状态
        dp[i][j] = max(dp[i - 1][j - 1] - prices[i], dp[i - 1][j]);
        // 第i天不持有 = i-1持有，今日卖出 ｜ 保持i-1天的不持有状态
        dp[i][j + 1] = max(dp[i - 1][j] + prices[i], dp[i - 1][j + 1]);
      }
    }
    return dp.back().back();
  }
};

int main() { return 0; }