/**
 * @Date: 2023 Dec 19
 * @Time: 10:22
 * @Author: Chris
 * @Title: 216.Combination Sum lll
 * @Link: https://leetcode.cn/problems/combination-sum-iii/description/
 **/
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
/// @brief [1,9] at most once,组合 不重复
class Solution {
 private:
  vector<vector<int>> res;
  vector<int> path;
  // 用sum来传递和
  // 左值引用+右值引用
  void backtracking(int &k, int &n, int &&start_index, int &&sum) {
    if (path.size() == k) {
      if (n == sum) {
        res.emplace_back(path);
      }
      return;
    }
    for (int i = start_index; i <= 9; ++i) {
      if (sum + i > n) break;  // 剪枝 和>n没必要遍历了
      path.emplace_back(i);
      backtracking(k, n, i + 1, sum + i);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    backtracking(k, n, 1, 0);
    return res;
  }
};
int main() { return 0; }