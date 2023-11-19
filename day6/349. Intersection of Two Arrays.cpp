/**
 * @Date: 2023 Nov 20
 * @Time: 00:09
 * @Author: Chris
 * @Desc: 349. Intersection of Two Arrays
 * @Link: https://leetcode.cn/problems/intersection-of-two-arrays/description/
 **/
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    // 返回交集的数组，数组中的元素唯一不重复。
    unordered_set<int> result_set;
    unordered_set<int> nums_set(nums1.begin(), nums1.end());
    for (int num : nums2) {
      // 如果没有找到，返回 end()
      if (nums_set.find(num) != nums_set.end()) {
        // 找到重复元素，插入
        result_set.insert(num);
        nums_set.erase(num);  // 在 nums_set中删除这个元素，避免下次重复查找。
      }
    }
    return vector<int>(result_set.begin(), result_set.end());
  }
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    // 数组hash值法
    unordered_set<int> result_set;
    int hash[1001] = {0};
    for (int num : nums1) {
      hash[num] = 1;
    }
    for (int num : nums2) {
      if (hash[num] == 1) {
        // 找到重复元素，插入
        result_set.insert(num);
      }
    }
    return vector<int>(result_set.begin(), result_set.end());
  }
};
int main() { return 0; }