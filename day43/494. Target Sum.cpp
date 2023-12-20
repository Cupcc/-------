/**
 * @Date: 2023 Dec 20
 * @Time: 15:44
 * @Author: Chris
 * @Title: 494. Target Sum
 * @Link: https://leetcode.cn/problems/target-sum/description/
 **/
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
 public:
  // 1.问题转化 2.递推公式 3. 初始化
  // 分为两个集合，正数集合，负数集合
  // sum_P - sum_N = target
  // sum_P + sum_N = sum
  // sum_P = (sum - target)/2
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < target || ((sum - target) & 1) == 1) return 0;
    int bagSize = (sum - target) / 2;
    vector<int> dp(bagSize + 1);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = bagSize; j >= nums[i]; --j) {
        // 两个选择方案，加在一起，
        // 添加nums[i] 和不加nums[i]
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp[bagSize];
  }
};
int main() { return 0; }