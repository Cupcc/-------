/**
 * @Date: 2023 Dec 19
 * @Time: 11:38
 * @Author: Chris
 * @Title: 343. Integer Break
 * @Link:
 *https://leetcode.cn/problems/integer-break/
 **/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  /// @brief
  /// 动态规划优化时间复杂度
  /// O(n)
  /// @param n
  /// @return
  int integerBreak(int n) {
    // 其实也是利用利用数学方法，
    // 得知尽可能的多拆分出3或3
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
      dp[i] =
          max(max(2 * (i - 2), 2 * dp[i - 2]), max(3 * (i - 3), 3 * dp[i - 3]));
    }
  }
};

/// @brief dp动态规划
class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[2] = 1;
    // dp是连乘，每次拆成2个数字相乘，如果本身大>相乘，可以不拆。
    for (int i = 3; i <= n; ++i) {
      /// @param j
      /// 拆分出来的一个数字，拆出来的两个数相等时才为最大值。
      /// 并且 i=4, j=1和j=3
      /// 都是 1*3 和 3*1.
      for (int j = 1; j <= i / 2; ++j) {
        // 注意使用滚动数组，dp[i]是历史数据
        dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
      }
    }
    return dp[n];
  }
};

/// @brief 贪心算法
class Solution {
 public:
  // 涉及到数学原理， (n1 + n2
  // + n3)/n <= \sqrt{n1^2 +
  // n2^2 + n3^2}{n}
  int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n == 4) return 4;
    int result = 1;
    while (n > 4) {
      result *= 3;
      n -= 3;
    }
    // n>4, n最小为5, n-3->2
    // 所以跳出时，n的范围2，3，4
    // 当为4的时候，2个2比一个3要大，
    // 2*2 > 3
    result *= n;
    return result;
  }
};
int main() { return 0; }