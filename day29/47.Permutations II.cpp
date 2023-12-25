/**
 * @Date: 2023 Dec 24
 * @Time: 23:55
 * @Author: Chris
 * @Title: 47.Permutations II
 * @Link: https://leetcode.cn/problems/permutations-ii/description/
 **/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <vector>

#include "doctest.h"
using namespace std;
// 重复元素的排列
class Solution {
 private:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(vector<int>& nums, vector<bool>& used) {
    if (nums.size() == path.size()) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      // 同层去重，当前层前一个元素没有用过的前提下，但本元素和其重复了
      // 意味着使用第一个没有用过的，后面的相同的都去掉。
      // 如果第一个使用过了，说明在上一层使用过的。
      // 那么我们可以继续使用第二个相同的元素
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
      if (used[i] == true) continue;
      path.push_back(nums[i]);
      used[i] = true;
      backtracking(nums, used);
      used[i] = false;
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<bool> used(nums.size() + 1, false);
    sort(nums.begin(), nums.end());
    backtracking(nums, used);
    return res;
  }
};
TEST_CASE("Testing permuteUnique function") {
  Solution solution;

  SUBCASE("Example test case") {
    // Prepare input and expected output
    std::vector<int> input = {1, 2, 2};
    std::vector<vector<int>> expected_output
        = {{1, 2, 2}, {2, 1, 2}, {2, 2, 1}};

    // Call the function and check the result using doctest macros
    CHECK(solution.permuteUnique(input) == expected_output);
  }
}