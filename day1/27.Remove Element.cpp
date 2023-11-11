#include "vector"
using namespace std;
class Solution {
 public:
  // 双指针；保持了原order
  int removeElement(vector<int>& nums, int val) {
    // 用于记录不等于val的元素的位置（需要删除）。
    auto it = nums.begin();

    for (auto& item : nums) {
      // 如果当前元素不等于val（需要保留），那么移动到it的位置。
      if (item != val) {
        *it++ = item;  // *it = item, it=it+1;
      }
    }
    // // 删除剩余元素
    nums.erase(it, nums.end());

    return nums.size();
    // //若不删除，可以直接返回it位置的个数。
    // return distance(nums.begin(),it);
  }
};

class Solution {
 public:
  // 相向双指针，避免了多次移动元素，改变了数组顺序。
  int removeElement(vector<int>& nums, int val) {
    for (size_t i = 0; i < nums.size();) {  // size_t非负数，更安全。
      // 最后面的元素移动过来，覆盖当前==val的元素。
      if (nums[i] == val) {
        // 移动最后一个元素到当前位置，并删除最后一个元素。
        nums[i] = move(nums.back());
        nums.pop_back();
        // 不需要递增，因为，进入下一次循环，需要判断移动到i位置的新元素。
      } else {
        ++i;
      }
    }
    return nums.size();
  }
};
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int left = 0;
    int right = nums.size() - 1;  // 区间[left,right]
    while (left <= right) {
      // 将右侧不需要删除的元素，移动到，左侧需要删除的位置。
      if (nums[left] == val) {       // 左侧发现要删除的元素
        if (nums[right] != val) {    // right的值不是要删除的
          nums[left] = nums[right];  // 移动right到left位置
        }
        // right是要删除的值,往左移动-1，不是要删除的也-1.
        --right;
      } else {
        ++left;  // left不是要删除的，right不动，更新left
      }
    }
    // nums.erase(nums.begin()+left, nums.end());
    return left;  // left最终大于right，即数组的右边界+1。
  }
};