/**
 * @Date: 2023 Dec 21
 * @Time: 09:46
 * @Author: Chris
 * @Title: 377. Combination Sum IV
 * @Link:
 *https://leetcode.cn/problems/combination-sum-iv/description/
 **/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  // 这题允许重复，是排列(1,3) (3,1)
  int combinationSum4(vector<int>& nums, int target) {
    vector<long> dp(target + 1);
    dp[0] = 1;
    for (int j = 0; j <= target; ++j)
      for (int num : nums)
        // 用减法判断大数溢出，否则加法还会溢出
        // 这个是中间结果，不影响最后结果
        if (j >= num && dp[j] < INT_MAX - dp[j - num])
          dp[j] += dp[j - num];

    return dp[target];
  }
};
int main() { return 0; }