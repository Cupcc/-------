/**
 * @Date: 2023 Nov 20
 * @Time: 00:47
 * @Author: Chris
 * @Desc: 1. Two Sum
 * @Link: https://leetcode.cn/problems/two-sum/description/
 **/
#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      auto iter = map.find(target - nums[i]);
      // 找到了
      if (iter != map.end()) {
        return {iter->second, i};  // 返回vector
      }
      map.insert(pair<int, int>(nums[i], i));  // 插入数字和索引。
    }
    return nums;
  }
};
int main() {
  vector<int> a = {1, 2, 3, 4, 5};
  return 0;
}