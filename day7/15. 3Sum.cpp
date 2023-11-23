/**
 * @Date: 2023 Nov 21
 * @Time: 10:30
 * @Author: Chris
 * @Desc: 15. 3Sum
 * @Link: https://leetcode.cn/problems/3sum/description/
 **/
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    // 双指针
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        return res;
      }
      // 错误去重a方法，比如-1,-1,2
      // 遇到第一个-1 就会跳过，导致漏掉-1,-1,2 这种情况,
      /*
      if (nums[i] == nums[i + 1]) {
          continue;
      }
      */
      // 去重复
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      // left在左边， right 在右边，逐渐往中间移动
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        int num = nums[i] + nums[left] + nums[right];
        if (num > 0)
          right--;
        else if (num < 0)
          left++;
        else {
          res.push_back(vector<int>{nums[i], nums[left], nums[right]});
          // 去重复，重了就跳过，因为同时处理 left 和 right，所以同时去重。
          while (right > left && nums[right] == nums[right - 1]) right--;
          while (right > left && nums[left] == nums[left + 1]) left++;

          // 找到答案了，双指针同时移动
          right--;
          left++;
        }
      }
    }
    return res;
  }

  // 无重复i,j,k，meet nums[i] + nums[j] + nums[k] = 0
  // 返回的集合必须无重复三元组，the solution set must not contain duplicate
  // triplets. 注意[0， 0， 0， 0] 这组数据 第一层for循环a，
  // 第二层for循环所有b,c。判断符合条件的c是否在set中
  vector<vector<int>> threeSum1(vector<int>& nums) {
    // hash 法
    vector<vector<int>> res = {};

    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        break;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        // a去重复，因为排好序了，确保不和上一个相等就不会出现重复元素a。
        continue;
      }
      unordered_set<int> set;  // 用来记录剩下的两对数据。
      for (size_t j = i + 1; j < nums.size(); j++) {
        if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) {
          // 三元组元素b去重
          continue;
        }
        int c = 0 - (nums[i] + nums[j]);
        if (set.find(c) != set.end()) {  // 如果c在集合中
          res.push_back({nums[i], nums[j], c});
          set.erase(c);  // 去除重复元素c.
        } else {
          set.insert(nums[j]);
        }
      }
    }

    return res;
  }
};

// 用来检测两个三元组是否相同
bool areSameTriplets(const vector<vector<int>>& a,
                     const vector<vector<int>>& b) {
  set<set<int>> setA, setB;
  for (const auto& v : a) setA.insert({v.begin(), v.end()});
  for (const auto& v : b) setB.insert({v.begin(), v.end()});
  return setA == setB;
}

// 测试函数
// Test function
void testThreeSum(const vector<int>& nums,
                  const vector<vector<int>>& expected) {
  // 做一个copy
  vector<int> nonConstnums = nums;
  auto result = Solution().threeSum(nonConstnums);
  if (areSameTriplets(result, expected)) {
    cout << "Test passed." << endl;
  } else {
    cout << "Test failed." << endl;
  }
}

int main() {
  // Test case 1
  testThreeSum({-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}});

  // Test case 2
  testThreeSum({0, 1, 1}, {});

  // Test case 3
  testThreeSum({0, 0, 0}, {{0, 0, 0}});

  // Add more test cases as needed

  return 0;

  return 0;
}