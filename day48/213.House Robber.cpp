/**
 * @Date: 2023 Dec 26
 * @Time: 09:40
 * @Author: Chris
 * @Title: 213.House Robber
 * @Link: https://leetcode.cn/problems/house-robber-ii/
 **/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// houses are arranged in a circle
class Solution {
  // 1. 问题分析与确定dp
  //   物品，房子
  //   背包，房子的数量
  //   dp[j] 当前j个房子，可抢劫的最大价值。
  // 2. 问题类型，01背包求最值
  // 3. 递推公式 抢与不抢，
  //          dp[j] = max(dp[j-2]+nums[i], dp[j-1]);
  //  去掉一个就不成环了，[0, end-1] , [1, end] 两种方案求最大值
 public:
  int rob(vector<int>& nums) {
    auto robSingle = [](auto begin, auto end) {
      int pre = 0;
      int res = 0;
      for (auto it = begin; it != end; ++it) {
        int max_temp = max(res, pre + *it);
        pre = res;
        res = max_temp;
      }
      return res;
    };
    return nums.size() == 1 ? nums[0]
                            : max(robSingle(nums.begin(), nums.end() - 1),
                                  robSingle(nums.begin() + 1, nums.end()));
  }
};
int main() { return 0; }