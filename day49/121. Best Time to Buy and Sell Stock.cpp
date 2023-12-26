/**
 * @Date: 2023 Dec 26
 * @Time: 12:18
 * @Author: Chris
 * @Title: 121. Best Time to Buy and Sell Stock
 * @Link:
 *https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/
 **/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

#include "../include/doctest.h"
using namespace std;
class Solution {
  // dp[j] 第j天的最大利润
  // 买 or 卖  or 不操作
  // 只能操作1次买和1次卖
 public:
  int maxProfit(vector<int>& prices) {
    // 第i天  1.持有股票：
    //          a. i-1天持有，无操作，继续持有，
    //          b. 今天买入, 
    //       2. 不持有股票
    //          a. i-1天不持有，无操作，继续不持有。
    //          b. i-1天持有，今天卖掉。
    // 0持有股票， 1不持有股票
    vector<vector<int>> dp(2, vector<int>(2));
    // 初始化
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < prices.size(); ++i) {
      // 只能买一次所以直接 -prices[i]，不加历史收益。
      dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
      dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
    }
    //一定不持有最大
    return dp[(prices.size() - 1) % 2][1];
  }
  int greedy(vector<int>& prices) {
    int low = INT_MAX;
    int res{0};  //小心要初始化，采用统一初始化格式
    for (int price : prices) {
      // 左侧最小值
      low = min(low, price);
      res = max(price - low, res);
    }
    return res;
  }
};

TEST_CASE("test greedy method") {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  int expected = 5;
  Solution s;
  CHECK(s.greedy(prices) == expected);
}
