/**
 * @file 714. Best Time to Buy and Sell Stock with Transaction Fee.cpp
 * @brief 714. Best Time to Buy and Sell Stock with Transaction Fee
 * \attention have transaction fee
 * @author Chris
 * @date 2023-12-28
 * @see https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 */
#include <vector>
using namespace std;

/// @brief 动态规划
class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    /// dp[i][0] 持有股票, dp[i][1] 不持有股票
    dp[0][0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      ///  持有  = 保持持有状态 ｜ 不持有，今日买入
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      /// 不持有 = 保持不持有状态 ｜ 持有状态，今日卖出 - 手续费
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }
    return dp.back().back();
  }
};
/// @brief 贪心算法
class Solution2 {
 public:
  /** 2个操作：
   *     买入： 遇到最低点记录,买入点
   *     卖出： 价格大于（最低价格+手续费）就可卖出， 连续交易，有差价就赚
   */
  int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    auto greedy = [](vector<int> prices, int fee) {
      int res = 0;
      int minPrice = prices[0];  ///< 记录最低价
      for (int i = 1; i < prices.size(); ++i) {
        /// 记录最低价,这是我们买入是价格
        if (prices[i] < minPrice) minPrice = prices[i];

        /// 只要有的赚我们就卖了再买，进行连续小额交易，==
        /// 一次大额度、高差价交易。 但是我们只要扣除最后一次手续费即可。
        if (prices[i] > minPrice + fee) {
          res += prices[i] - minPrice - fee;
          /// 如果单调递增，进行连续交易，那么minPrice存储的就是当前prices[i]价格
          /// 这可以避免扣除中间多余的手续费
          minPrice = prices[i] - fee;  ///< 记录当前价格
        }
      }
      return res;
    };
    return greedy(prices, fee);
  }
};
