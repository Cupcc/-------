/**
 * @Date: 2023 Dec 19
 * @Time: 08:31
 * @Author: Chris
 * @Title: 77. Combinations
 * @Link: https://leetcode.cn/problems/combinations/description/
 **/
#include <iostream>
#include <vector>
using namespace std;
/// @brief 组合问题，不能重复,从start开始遍历。
//// 遍历[1,n]个数字，一共n-1 + 1个数.
class Solution {
 private:
  vector<vector<int>> result;
  vector<int> path;
  // [1, n] 一共(n-1)+ 1 个元素
  // [i, n] 一共(n-i)+ 1 个元素
  // 序列中需要的元素个数: k
  // 已经包含的元素个数: path.size()
  // 还需要的元素的个数： k - path.size()
  void backtracking(int n, int k, int startIndex) {
    if (path.size() == k) {
      result.emplace_back(path);
      return;
    }
    // 需要的个数>还剩的个数时，不用继续遍历，遍历完也无法满足条件。
    // 反过来讲：还需要的个数<= 还剩下的个数
    // 还需要的个数 <= [i,n]范围剩下元素的个数
    // k - path.size() <= n-i + 1
    for (int i = startIndex; i <= n + 1 - (k - path.size()); ++i) {
      path.push_back(i);
      backtracking(n, k, i + 1);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combine(int n, int k) {
    backtracking(n, k, 1);
    return result;
  }
};
int main() { return 0; }