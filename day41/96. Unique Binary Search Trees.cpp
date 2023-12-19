/**
 * @Date: 2023 Dec 19
 * @Time: 14:41
 * @Author: Chris
 * @Title: 96. Unique Binary Search Trees
 * @Link: https://leetcode.cn/problems/unique-binary-search-trees/description/
 **/
#include <iostream>
#include <vector>
using namespace std;

/// @brief 把节点依次设为根。
// 分别计算左子树的不同类型的个数 * 右子树不同类型的个数。
// 记住这是BST搜索树，left < root < right
//  if i = 5, then
//  dp[5] = 0;
//  1) root=node(1), 比1小的0个，比1大的4个
//            then, dp[5] += dp[0] * dp[4]
//  2) root=node(2), 比2小的1个，比2大的3个
//            then, dp[5] += dp[1] * dp[3]
//  3) root=node(3), 比3小的2个，比3大的2个
//            then, dp[5] += dp[2] * dp[2]
//  4) root=node(4), 比4小的3个，比4大的1个
//            then, dp[5] += dp[3] * dp[1]
//  5) root=node(5), 比5小的4个，比5大的0个
//            then, dp[5] += dp[4] * dp[0]
class Solution {
 public:
  // dp[i]:  (由i个节点组成)不同的二叉搜索树的个数。
  int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      // j为不同的节点当作root
      // root = node(j), 比j小的j-1个，比j大的i-j个。
      //     then, dp[i] += dp[j-1] * dp[i-j]
      //     j一直从 1 遍历到 i.
      for (int j = 1; j <= i; ++j) {
        int leftNum = dp[j - 1];
        int rightNum = dp[i - j];
        dp[i] += leftNum * rightNum;
      }
    }
    return dp[n];
  }
};
int main() { return 0; }