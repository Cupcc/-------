/**
 * @Date: 2023 Dec 23
 * @Time: 08:38
 * @Author: Chris
 * @Title: 90. Subsets
 * @Link: https://leetcode.cn/problems/subsets-ii/description/
 **/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 private:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(vector<int>& nums, int startIndex) {
    res.push_back(path);
    for (int i = startIndex; i < nums.size(); ++i) {
      // 比较的时候不能包括第一个，要从第二个和第一个比较。
      // 如果包括，那么将是第一个元素和[i-1]为上一层的元素进行比较了。
      // 不同层可以重复！同层不能重复
      // 比如 [1, 2, 2]第二个位置的2，可以和第三个地位置的2重复，这是不同层的。
      // 但是第二个位置不能重复选择2， 一个位置代表同一层
      if (i > startIndex && nums[i] == nums[i - 1]) continue;

      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    backtracking(nums, 0);
    return res;
  }
};
int main() { return 0; }