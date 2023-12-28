/**
 * @file 309. Best Time to Buy and Sell Stock with Cooldown.cpp
 * @brief Best Time to Buy and Sell Stock with Cooldown
 * can complete many transactions but must sell the stock before buy again.
 * \attention cooldown one day
 * @author Chris
 * @date 2023-12-28
 * @see https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <algorithm>
#include <iostream>
#include <vector>

#include "../include/doctest.h"

using namespace std;

class Solution {
 public:
  /**
   * @brief 动态规划
   * 状态： 持有状态: 0.今天买入,或已经买入
   *     不持有状态: 1.今天卖出
   *               2.冷冻期 (昨日卖出)
   *               3.过了冷冻期 (早已卖出)
   */
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(4));
    dp[0][0] = -prices[0];
    for (int i = 1; i < n; ++i) {
      //! 0.持有 = 已经持有，继续保持状态 ｜(昨日冷冻期or过了冷冻期)今天买
      dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][2], dp[i - 1][3]) - prices[i]);
      //! 1.今日卖出 = 昨日持有，今天卖
      dp[i][1] = dp[i - 1][0] + prices[i];
      //! 2.冷冻期 = 昨日卖出
      dp[i][2] = dp[i - 1][1];
      //! 3.过了冷冻期 = 昨天过了冷冻期，继续处于这个状态｜昨日冷冻期
      dp[i][3] = max(dp[i - 1][3], dp[i - 1][2]);
    }
    return *max_element(dp.back().begin() + 1, dp.back().end());
  }
};

/// @fn test function
TEST_CASE("Testing function") {
  Solution s;
  SUBCASE("case 1") {
    vector<int> prices1 = {1, 2, 3, 0, 2};
    CHECK(s.maxProfit(prices1) == 3);
  }
  SUBCASE("case 2") {
    vector<int> prices2 = {1};
    CHECK(s.maxProfit(prices2) == 0);
  }
}