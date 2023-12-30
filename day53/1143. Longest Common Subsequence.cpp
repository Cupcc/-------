/**
 * @file 1143. Longest Common Subsequence.cpp
 * @brief
 *  不要求连续
 * @author Chris
 * @date 2023-12-30
 * @see https://leetcode.cn/problems/longest-common-subsequence/
 */

#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  /**
   * @brief 动态规划  当前状态只与上一个状态有关。
   *                 当前状态可以由之前的状态推导出来。
   * 第i个位置的下标是i-1
   * dp[i][j]含义：前i个索引[0,i-1]的text1 和
   * 前j个索引[0,j-1]的text2的最长公共子序列长度。
   * 递推公式:
   * 1。text[i-1]与text[j-1]相同，2。text[i-1]与text[j-1]不同
   * dp[i][j] = dp[i-1][j-1] + 1
   * dp[i][j] = max(dp[i-1][j], dp[i][j-1])
   * @param text1
   * @param text2
   * @return int
   */
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = 1; i <= text1.size(); ++i) {
      for (int j = 1; j <= text2.size(); ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          /// 如果相等，那么就加上这个元素
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          /// 如果不想等，那么选择少一个text1元素或者少一个text2元素的最大值。
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp.back().back();
  }
};