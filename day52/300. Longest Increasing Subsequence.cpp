/**
 * @file 300. Longest Increasing Subsequence.cpp
 * @brief 300. Longest Increasing Subsequence
 * \attention strictly increaing subsequence
 * @author Chris
 * @date 2023-12-29
 * @see https://leetcode.cn/problems/longest-increasing-subsequence/
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "../include/doctest.h"

using namespace std;

class Solution {
 public:
  /**
   * @brief dp[i]记录以nums[i]结尾的最长递增的子序列长度（可以不连续但严格递增）
   * 然后返回dp[i]的最大值
   */
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    // 类比背包问题，外层是容量
    for (int i = 1; i < nums.size(); ++i) {
      // 内层扫描物品
      for (int j = 0; j < i; ++j) {
        // 如果找到比当前物品小的值，递增序列从j位置添加nums[i]元素。长度+1
        if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};

TEST_CASE("test lenthOfLIS") {
  Solution s;
  SUBCASE("case 1") {
    vector<int> nums1{10, 9, 2, 5, 3, 7, 101, 18};
    CHECK(s.lengthOfLIS(nums1) == 4);
  }
  SUBCASE("case 2") {
    vector<int> nums2{0, 1, 0, 3, 2, 3};
    CHECK(s.lengthOfLIS(nums2) == 4);
  }
  SUBCASE("case 3") {
    vector<int> nums3{7, 7, 7, 7, 7};
    CHECK(s.lengthOfLIS(nums3) == 1);
  }
}
