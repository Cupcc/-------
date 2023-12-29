/**
 * @file 718. Maximum Length of Repeated Subarray.cpp
 * @brief 718. Maximum Length of Repeated Subarray
 *
 * @author Chris
 * @date 2023-12-29
 * @see https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    // 索引从1开始代表第i个元素，空出0位置便于初始化进行递推
    vector<int> dp(nums2.size() + 1, 0);

    // 遍历两个数组
    for (int i = 1; i <= nums1.size(); ++i) {
      // 从后向前遍历，避免覆盖历史记录
      for (int j = nums2.size(); j > 0; --j) {
        // 第i个元素索引为i-1
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[j] = dp[j - 1] + 1;
        } else dp[j] = 0;  ///< 注意滚动数组需要手动置0
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};