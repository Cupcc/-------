/**
 * @Date: 2023 Dec 24
 * @Time: 23:09
 * @Author: Chris
 * @Title: 46. Permutations
 * @Link: https://leetcode.cn/problems/permutations/description/
 **/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 private:
  vector<vector<int>> res;
  vector<int> path;
  template <size_t N>
  void backtracking(vector<int>& nums, int (&used)[N]) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }
    //排列问题顺序可以颠倒，所以我们从for循环0开始遍历，意味着所有的元素都可以选择
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i + 10] == 1) continue;
      path.push_back(nums[i]);
      used[i + 10] = 1;
      backtracking(nums, used);
      used[i + 10] = 0;
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    int used[21];
    backtracking(nums, used);
    return res;
  }
};

class Solution2 {
 private:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(vector<int>& nums, vector<bool>& used) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }
    // 从0开始遍历，意味着从所有的元素都可以选择，
    // 但不能选择选过的元素，
    //  比如，给定数组[1,2,3,4]
    //  当前答案序列[1,4,] 遍历到第3个位置，不能选择1,4了
    //  这叫同一路径不可重复！！！！
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i + 10] == true) continue;
      path.push_back(nums[i]);
      used[i + 10] = true;
      backtracking(nums, used);
      used[i + 10] = false;
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return res;
  }
};
int main() { return 0; }