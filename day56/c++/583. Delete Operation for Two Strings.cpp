/**
 * @file 583. Delete Operation for Two Strings.cpp
 * @brief
 *
 * @author Chris
 * @date 2024-01-02
 * @see https://leetcode.cn/problems/delete-operation-for-two-strings/description/
 */

#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  /// 找到最大公共子序列，减去公共长度，就是最小要编辑的次数了！
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    ///< 注意每一个字符串都需要减去公共部分
    return m + n - dp[m][n] * 2;
  }
};