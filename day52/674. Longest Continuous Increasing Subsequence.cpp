/**
 * @file 674. Longest Continuous Increasing Subsequence.cpp
 * @brief 674. Longest Continuous Increasing Subsequence
 *
 * @author Chris
 * @date 2023-12-29
 * @see https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/
 */

#include <vector>
using namespace std;
class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int res = 1;
    int pre = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        res = max(res, ++pre);
      } else {
        pre = 1;
      }
    }
    return res;
  }
  int _findLengthOfLCIS(vector<int>& nums) {
    int res = 1;
    int sub = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        sub++;
      } else {
        res = max(res, sub);
        sub = 1;
      }
    }
    return res;
  }
};