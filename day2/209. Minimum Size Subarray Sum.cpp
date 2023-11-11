/**
 * @Date: 2023 Nov 10
 * @Time: 03:04
 * @Author: Chris
 * @Desc:
 * Given an array of positive integers nums and a positive integer target,
return the minimal length of a subarray whose sum is greater than or equal to
target. If there is no such subarray, return 0 instead.


Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem
constraint.
 **/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int length = INT32_MAX;  // 求最小长度，初始化为最大
    int sum = 0;
    for (size_t i = 0, j = 0; j < nums.size(); j++) {
      sum += nums[j];
      // 如果右侧添加一个较大的数字，左侧可能会连续缩小
      while (sum >= target) {
        length = j - i + 1 < length ? j - i + 1 : length;
        sum -= nums[i++];
        
      }
    }
    // 如果没有改变，返回0
    return length == INT32_MAX ? 0 : length;
  }
};
int main() { return 0; }