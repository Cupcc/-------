/**
 * @Date: 2023 Dec 20
 * @Time: 12:29
 * @Author: Chris
 * @Title: 1049. Last Stone Weight Il
 * @Link: https://leetcode.cn/problems/last-stone-weight-ii/description/
 **/
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
  // target 背包容量
  // nums 物品
 public:
  // 问题转化为：把石头分为两堆，使其能正好消掉，如何分呢，
  // 每个背包的容量就是 sum/2 ，往里面开始放石头，放石头的方法挑选最大值放法。
  // 这样可以确保 sum/2背包容量的，达到最大值！ 因为 sum/2向下取整，
  // 第一个背包(sum - sum/2) >= 第二个背包(sum/2)
  // 使其正好消掉，尽量让其相等！ 何时尽量相等？ 即求第二个背包(sum/2)的最大值！
  // 问题转化： sum/2的背包容量，这个背包能最大装多少石头？
  int lastStoneWeightII(vector<int>& stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;
    vector<int> dp(target + 1);
    // 遍历物品
    for (int i = 0; i < stones.size(); ++i) {
      // 遍历背包
      for (int j = target; j >= stones[i]; --j) {
        dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }
    return sum - dp[target] - dp[target];
  }
};

int main() { return 0; }