/**
 * @Date: 2023 Dec 28
 * @Time: 00:09
 * @Author: Chris
 * @Title: 746. Min Cost Climbing Stairs
 * @Link: https://leetcode.cn/problems/min-cost-climbing-stairs/
 **/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
  //  最值问题
  //   dp[j] 爬到j层的最小花费,
  //  一共要爬到cost.size()层
  //  状态推导:  当前阶梯=可爬1步或爬2步
  //      dp[j] = min(dp[j-1]+cost[i-1], dp[j-2] + cost[j-2])
  // 初始化dp[1] = dp[0]
  int minCostClimbingStairs(vector<int>& cost) {
    //[1,3,4], 注意要登顶就是爬出序列外,求dp[4]=dp[cost.size()];
    vector<int> dp(cost.size() + 1);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= cost.size(); ++i) {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp.back();
  }
};
class Solution2 {
 public:
  /// 空间优化
  int minCostClimbingStairs(vector<int>& cost) {
    int pre = 0, cur = 0;
    int n = cost.size();
    for (int i = 2; i <= n; ++i) {
      //  状态推导:  当前阶梯花费=可爬1步或爬2步
      //      dp[j] = min(dp[j-1]+cost[i-1], dp[j-2] + cost[j-2])
      int min_cost = min(pre + cost[i - 2], cur + cost[i - 1]);
      pre = cur;
      cur = min_cost;
    }
    return cur;
  }
};
int main() { return 0; }