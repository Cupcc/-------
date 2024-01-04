/**
 * @file 739. Daily Temperatures.cpp
 * @brief
 *
 * @author Chris
 * @date 2024-01-04
 * @see
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(const vector<int>& nums) {
  vector<int> result(nums.size(), -1);
  stack<int> s;  // 保存索引
  for (int i = 0; i < nums.size(); ++i) {
    while (!s.empty() && nums[i] > nums[s.top()]) {
      result[s.top()] = nums[i];  // 更新数组
      s.pop();
    }
    s.push(i);
  }
  return result;
}
int main() {
  vector<int> nums = {2, 7, 3, 5, 4};
  auto result = nextGreaterElement(nums);

  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}