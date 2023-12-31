/**
 * @file 53. Maximum Subarray.cpp
 * @brief 53. Maximum Subarray
 * @author Chris
 * @date 2023-12-31
 * @see https://leetcode.cn/problems/maximum-subarray/description/
 */
#include <climits>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "../include/doctest.h"
using namespace std;

/**
 * @attention 从例子中注意到子序列需要是连续的
 * 比如输入序列[1,2,3,4,5]
 * 答案子序列可以是[2,3,4],但不可是[1,4,5]
 */
class Solution {
 public:
  /**
   * @brief 动态规划
   * 1. dp的含义：dp[i] = 长度为i的子序列的的和的最大值
   * 2.递推公式 子序列求和必须是连续的，所以我们不考虑，也不进行不连续元素的求和
   * 这意味着，dp[i]是必须要包含nums[i]的，
   *         这就能确保从上一个状态转化到下一个状态一定是连续的序列求和。
   *  因此， 当前状态 = 上一个状态+nums[i], 只有nums[i]本身求和
   *        也可以理解为，dp[j-1]<0，我们就从nums[i]开始求和。
   *  ==>   dp[i] = (dp[i-1] + nums[i], nums[i]);
   * 3. 初始化 dp[0] = 第一个元素的自己求和
   * @param nums
   * @return int
   */
  int maxSubArray(vector<int>& nums) {
    /// 当dp索引代表个数的时候才+1. 即dp[i]遍历nums[i-1]
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }
    return *max_element(dp.begin(), dp.end());
  }
};

class Solution2 {
 public:
  int maxSubArray(vector<int>& nums) {
    ///  res需要初始化
    int max_val = 0, res = nums[0];
    for (int num : nums) {
      max_val = max(max_val + num, num);
      res = max(res, max_val);
    }
    return res;
  }
};
TEST_CASE("test maxSubArray") {
  Solution s;
  SUBCASE("case 1") {
    vector<int> nums1{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    CHECK(s.maxSubArray(nums1) == 6);
  }
  SUBCASE("case 2") {
    vector<int> nums2{1};
    CHECK(s.maxSubArray(nums2) == 1);
  }
  SUBCASE("case 3") {
    vector<int> nums3{5, 4, -1, 7, 8};
    CHECK(s.maxSubArray(nums3) == 23);
  }
}
