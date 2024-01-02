/**
 * @file 392.Is Subsequence.cpp
 * @brief
 *
 * @author Chris
 * @date 2024-01-02
 * @see https://leetcode.cn/problems/is-subsequence/
 */

#include <string>
#include <vector>
using namespace std;
///
class Solution {
 public:
  /// whether s is a subsequence of t.
  bool isSubsequence(string s, string t) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j <= t.size(); ++j) {
        if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
        /// s 是 t的子序列，s要完整匹配，t可以缺少元素
        else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
    return dp.back().back() == s.size();
  }
};