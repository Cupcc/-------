/**
 * @Date: 2023 Dec 03
 * @Time: 17:56
 * @Author: Chris
 * @Desc: 239.Sliding Window Maximum
 * @Link: https://leetcode.cn/problems/sliding-window-maximum/description/
 **/
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
class MyQueue {
  // 维护单调递减队列
 private:
  deque<int> que;

 public:
  // 弹出自己，如果自己不在队列中，无操作。
  // 因为比自己大的value进队列的时候，自己可能被弹出了。
  void pop(int value) {
    if (!que.empty() && value == que.front()) {
      que.pop_front();
    }
  }

  // 弹出队列末尾中小于value的值，然后入队。
  void push(int value) {
    while (!que.empty() && value > que.back()) {
      que.pop_back();
    }
    que.push_back(value);
  }
  // 返回队列最大值
  int front() { return que.front(); }
};

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // 每次窗口滑动3步骤，
    // 1.移除前面的1个，
    // 2.加入后面的1个
    // 3.选择当前窗口最大的值
    MyQueue que;
    vector<int> result;
    for (uint i = 0; i < k; i++) {
      que.push(nums[i]);
    }
    result.push_back(que.front());
    for (uint i = k; i < nums.size(); i++) {
      que.pop(nums[i - k]);
      que.push(nums[i]);
      result.push_back(que.front());
    }

    return result;
  }
};

int main() { return 0; }