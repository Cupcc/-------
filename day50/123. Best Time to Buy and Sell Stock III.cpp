/**
 * @Date: 2023 Dec 27
 * @Time: 08:08
 * @Author: Chris
 * @Title: 123. Best Time to Buy and Sell Stock III
 * @Link:
 *https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/
 **/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // 滚动数组空间优化
  int maxProfit(vector<int>& prices) {
    //  状态分析：
    //          0. 第一次持有股票
    //          1. 第一次不持有
    //          2. 第二次持有股票
    //          3. 第二次不持有
    vector<int> dp(4, 0);
    dp[0] = -prices[0];
    dp[2] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      // dp[0]是求负数的最大值=求正数最小值，其实就是当前序列中最便宜的股票
      dp[0] = max(-prices[i], dp[0]);
      dp[1] = max(dp[0] + prices[i], dp[1]);
      dp[2] = max(dp[1] - prices[i], dp[2]);
      dp[3] = max(dp[2] + prices[i], dp[3]);
    }
    return dp.back();
  }
};

class Solution2 {
  // at most two transactions
  // mush sell the stock before buy again
 public:
  //  状态分析：
  //          0. 第一次持有股票
  //          1. 第一次不持有
  //          2. 第二次持有股票
  //          3. 第二次不持有
  int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(4));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[0][2] = -prices[0];
    dp[0][3] = 0;
    for (int i = 1; i < prices.size(); ++i) {
      // 第一次持有  = 第一次保持持有｜ i-1不持有 今日买入。
      // 注意第一次买入，不能加历史记录！和121题一致
      dp[i][0] = max(dp[i - 1][0], -prices[i]);
      // 第一次不持有 = 第一次保持不持有｜ i-1持有，今日卖出
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
      // 第二次持有   = 第二次保持持有｜ i-1第一次不持有，今日买入
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
      // 第二次不持有 = 保持第二次不持有｜第二次持有+今日卖出
      dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
    }
    return dp.back()[3];
  }
};
int main() { return 0; }