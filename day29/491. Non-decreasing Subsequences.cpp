/**
 * @Date: 2023 Dec 22
 * @Time: 08:51
 * @Author: Chris
 * @Title: 491. Non-decreasing Subsequences
 * @Link:
 *https://leetcode.cn/problems/non-decreasing-subsequences/description/https://leetcode.cn/problems/non-decreasing-subsequences/description/
 **/
#include <iostream>  // IWYU pragma: keep
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 private:
  vector<vector<int>> res;
  vector<int> path;

  void backtracking(vector<int> &nums, int indexStart) {
    if (path.size() > 1) res.push_back(path);
    // 在同一层进行标记
    unordered_set<int> set;

    for (int i = indexStart; i < nums.size(); ++i) {
      // 如果不是递增、如果重复了，都跳过
      if ((!path.empty() && nums[i] < path.back()) ||
          set.find(nums[i]) != set.end()) {
        continue;
      }
      path.push_back(nums[i]);
      set.insert(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    backtracking(nums, 0);
    return res;
  }
};
int main() { return 0; }