/**
 * @Date: 2023 Dec 23
 * @Time: 08:21
 * @Author: Chris
 * @Title: 78. Subsets
 * @Link: https://leetcode.cn/problems/subsets/description/
 **/
#include <iostream>
#include <vector>
using namespace std;
/// @brief 组合数，不重复，但可以空

class Solution {
  vector<vector<int>> res;
  vector<int> path;
  /// @brief 回溯三部曲
  ///       1. 函数参数
  ///       2. 递归终止条件
  ///       3. 单层搜索逻辑
  void backtracking(vector<int>& nums, int startIndex) {
    res.push_back(path);
    // 不用写终止，到了最底层，下面的for循环都进不去，就不再执行递归，函数直接结束。

    // 从startIndex开始，表明这一层选择的范围被限制。
    // 不能选选过的
    for (int i = startIndex; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    backtracking(nums, 0);
    return res;
  }
};
int main() { return 0; }