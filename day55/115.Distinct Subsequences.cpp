/**
 * @file 115.Distinct Subsequences.cpp
 * @brief
 *
 * @author Chris
 * @date 2024-01-02
 * @see https://leetcode.cn/problems/distinct-subsequences/description/
 */

#include <_types/_uint64_t.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  // dp[i][j] 以i-1为结尾的s子序列中出现以j-1为结尾的t的方案数为dp[i][j]。
  // 递推关系
  // 1。s[i-1]和t[j-1]相等
  //   可以用s[i-1]匹配，也可以不用。 需要把两种情况都算进去！dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
  //   当不用s[i-1] 匹配，可以用之前都匹配 比如s="abb" t="ab" 可以用s的第一个b也可以用s的第二个b匹配。
  // 2。s[i-1]和t[j-1]不相等
  //      dp[i][j] = dp[i-1][j] 不用s[i-1]来匹配，可以用之前的。因为序列中的字母可能重复
  //  例如： s = abbcd  t = abc
  //          abb和ab匹配时->用 ab和ab匹配。
  // 初始化 dp[i][0]=0,表示t="",从s中匹配空字符串方案数为1
  int numDistinct(string s, string t) {
    if (s.size() < t.size()) return 0;

    vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));

    for (int i = 0; i < dp.size(); ++i) dp[i][0] = 1;

    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j <= t.size(); ++j) {
        if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        else dp[i][j] = dp[i - 1][j];
      }
    }
    return dp.back().back();
  }
};
