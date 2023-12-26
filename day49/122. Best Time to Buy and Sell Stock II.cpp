/**
 * @Date: 2023 Dec 26
 * @Time: 14:31
 * @Author: Chris
 * @Title: 122. Best Time to Buy and Sell Stock II
 * @Link: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
 **/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  // can buy and sell it on the same day
  // hold at most one share of stock
 public:
  //   0持有，1不持有
  //  第i天
  //      持有 1. i-1不持有，今日不操作
  //          2. i-1天不持有，今日买入
  //      不持有
  //          1. i-1天持有，今日卖出
  //          2. i-1天不持有，今日不操作
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    vector<vector<int>> dp(len, vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; ++i) {
      // 可以买入多次，所以要用历史收益-prices[i]
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
    }
    return dp[len - 1][1];
  }
  // greedy
  int greedy(vector<int>& prices) {
    // 模型简化为只有3天。
    // 可能的情况，1。单调递减或全相等，那么我们不买不卖。即为0
    //  2.单调递增 那么第一买第三天卖=第一天买，第二天卖，第二天再买，第三天卖
    //           diff(1,3) = diff(1,2) + diff(2,3)
    //  3. 先增后减 [1 7 4],[6,9,1] 肯定是第一天买，第二天卖
    //  4. 先减后增 [4,1,8]
    //  肯定是第二天买，第三天卖，即我们相邻两天利润小于0的时候就不交易。
    //
    // 可以发现2条规律，1.只有增的时候我们买，2.隔天的买卖可以分割为连续的买卖
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      profit += max(prices[i] - prices[i - 1], 0);
    }
    return profit;
  }
};
int main() { return 0; }