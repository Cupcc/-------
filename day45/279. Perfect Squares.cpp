/**
 * @Date: 2023 Dec 22
 * @Time: 21:48
 * @Author: Chris
 * @Title: 279.Perfect Squares
 * @Link: https://leetcode.cn/problems/perfect-squares/description/
 **/
#include <climits>
#include <vector>

using namespace std;
class Solution {
 public:
  // dp含义: dp[j] 和为n所需要的最少完全平方数
  // 递推公式 dp[j] = min(dp[j], dp[j-i*i] + 1);
  // 初始化:   初始化为最大值 dp[0]= 0
  // 遍历顺序： 元素可重复，内外层顺序可替换，ij从小到大遍历
  int numSquares(int n) {
    // 最大值不会超过n，因为和为n,最多需要n个1.
    vector<int> dp(n + 1, n);
    dp[0] = 0;
    for (int i = 1; i <= n / 2; ++i) {
      for (int j = i * i; j <= n; ++j) {
        dp[j] = min(dp[j], dp[j - i * i] + 1);
      }
    }
    return dp[n];
  }
};
int main() { return 0; }