/**
 * @Date: 2023 Dec 19
 * @Time: 17:04
 * @Author: Chris
 * @Title: 40. Combination Sum Il
 * @Link: https://leetcode.cn/problems/combination-sum-ii/description/
 **/
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  // res中的path不能重复！ [[1,7],[1,7]]这是不可以的，因为1是
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(vector<int>& candidates, int target, int startIndex,
                    int sum) {
    if (sum == target) {
      res.emplace_back(path);
      return;
    }
    for (int i = startIndex; i < candidates.size(); ++i) {
      if (sum + candidates[i] > target) break;  // 提前退出,不用入栈
      // 同层去重法
      if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
      path.emplace_back(candidates[i]);
      backtracking(candidates, target, i + 1, sum + candidates[i]);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0);
    return res;
  }
};
int main() { return 0; }