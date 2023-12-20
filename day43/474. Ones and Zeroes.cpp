/**
 * @Date: 2023 Dec 20
 * @Time: 16:39
 * @Author: Chris
 * @Title: 474. Ones and Zeroes
 * @Link: https://leetcode.cn/problems/ones-and-zeroes/description/
 **/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/// @brief  求字符串的子集合
//          子集满足的要求， 所有字符串的不超过m个0和n个1
//          返回符合条件的子集中，最大的子集的集合大小（子集包含字符串的个数）
class Solution {
 public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    // dp[i][j]：最多有i个0和j个1的strs的最大子集的大小的为dp[i][j]。
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (string &str : strs) {
      int oneNum = count(str.begin(), str.end(), '1');
      int zeroNum = str.length() - oneNum;
      for (int i = m; i >= zeroNum; --i) {
        for (int j = n; j >= oneNum; --j) {
          // 第二项代表把当前字符串添加进去，
          // 当前字符串 1的个数oneNum
          //          0的个数zeroNum
          dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
        }
      }
    }
    return dp[m][n];
  }
};
int main() { return 0; }