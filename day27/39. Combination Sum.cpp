/**
 * @Date: 2023 Dec 19
 * @Time: 15:37
 * @Author: Chris
 * @Title: 39. Combination Sum
 * @Link: https://leetcode.cn/problems/combination-sum/description/
 **/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 private:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(vector<int>& candidate, int target, int start, int sum) {
    if (sum > target) return;
    if (sum == target) {
      res.emplace_back(path);
      return;
    }

    for (int i = start; i < candidate.size(); ++i) {
      path.emplace_back(candidate[i]);
      backtracking(candidate, target, i, sum + candidate[i]);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // 排个序再递归速度更快
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0);
    return res;
  }
};
int main() { return 0; }