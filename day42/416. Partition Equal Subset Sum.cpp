/**
 * @Date: 2023 Dec 18
 * @Time: 23:05
 * @Author: Chris
 * @Title: 416. Partition Equal Subset Sum
 * @Link: https://leetcode.cn/problems/partition-equal-subset-sum/description/
 **/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /// @brief size: nums.size()/2
  ///        goods: 每一个元素element
  ///        weight: 元素的值
  ///        value: 元素的值
  ///        重复性? No~
  /// @param nums
  /// @return
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    vector<int> dp(10001, 0);
    for_each(nums.begin(), nums.end(), [&sum](int x) { sum += x; });
    if (sum % 2 == 1) return false;
    int target = sum / 2;
    // dp
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }
    return dp[target] == target;
  }
};
int main() { return 0; }