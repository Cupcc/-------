/**
 * @file 62. Unique Paths.cpp
 * @brief
 *
 * @author Chris
 * @date 2023-12-31
 * @see https://leetcode.cn/problems/unique-paths/
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution2 {
 public:
  /// 组合数(m+n-2)C(m-1) = C(m+n-2, m-1)
  int uniquePaths(int m, int n) {
    if (m > n) swap(n, m);  ///< 利用对称性减少计算量
    int res = 1;
    for (int i = 1; i <= m - 1; ++i) {
      // (m+n-2) - (m-1) => n-1
      // 比如C(8,3) = 6/1 * 7/2 * 8/3
      res *= (n - 1 + i) / i;
    }
    return res;
  }
};

class Solution {
 public:
  int _uniquePaths(int m, int n) {
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[j] += dp[j - 1];  //累加
      }
    }
    return dp.back();
  }
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; ++i) dp[i][0] = 1;
    for (int j = 0; j < n; ++j) dp[0][j] = 1;

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j) {
        ///两条可行路径
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
      }

    return dp[m - 1][n - 1];
  }
};
int main() {
  Solution s;
  cout << (s.uniquePaths(3, 7) == 28) << endl;
}