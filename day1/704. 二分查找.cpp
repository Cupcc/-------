// go:build ignore
#include <iostream>
using namespace std;
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();  // 数组长度
    while (left < right) {
      int middle = left + ((right - left) >>
                           1);  // 左+半个区间，右移动1位=除以2,+-优先级高
      if (nums[middle] > target) {
        right = middle;  // right为右索引+1. 落在区间[left,middle)中
      } else if (nums[middle] < target) {
        left = middle + 1;  // 落在区间[middle + 1, right)
      } else {
        return middle;
      }
    }
    return -1;  // not existed
  }
};

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;  // target in [left, right]

    while (left <= right) {
      int middle = left + ((right - left) >> 1);  // 左区间
      if (nums[middle] > target) {
        right = middle - 1;
      } else if (nums[middle] < target) {
        left = middle + 1;
      } else {
        return middle;
      }
    }
    return -1;  // not existed
  }
};

int main() {}