/**
 * @Date: 2023 Dec 25
 * @Time: 22:42
 * @Author: Chris
 * @Title: 198. House Robber
 * @Link: https://leetcode.cn/problems/house-robber/description/
 **/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  // dp 6步
  // 物品 nums序列
  // 背包容量 nums.length
  // dp[j] 数组长度为j的nums序列中可打劫的最大金额
  //     打不打劫这一家？不打劫 dp[j] = dp[j-1];
  //                  打劫 dp[j] = dp[j-2] + nums[i];
  // 递推公式 dp[j] = max(dp[j-1], dp[j-2] + nums[i]);
  // 一家不能打劫两次， 01背包
 public:
  int rob(vector<int>& nums) {
    // 优化为3个变量
    int pre = 0;
    int res = 0;
    for (const int num : nums) {
      int tmp = res;
      // dp[j] = max(dp[j-1], dp[j-2] + nums[i]);
      res = max(res, pre + num);
      pre = tmp;
    }
    return res;
  }
};
int main() { return 0; }
