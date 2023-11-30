/**
 * @Date: 2023 Nov 30
 * @Time: 21:01
 * @Author: Chris
 * @Desc: 225.Implement Stack using Queues
 * @Link: https://leetcode.cn/problems/implement-stack-using-queues/description/
 **/
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
 public:
  queue<int> qMain;
  queue<int> qAsist;
  MyStack() {}

  void push(int x) { qMain.push(x); }

  int pop() {
    int res;

    while (qMain.size() != 1) {
      qAsist.push(qMain.front());
      qMain.pop();
    }
    res = qMain.front();
    qMain.pop();

    qMain = qAsist; //可以直接复制辅助队列。
    while (!qAsist.empty()) qAsist.pop();

    return res;
  }

  int top() {
    // int res = this->pop();
    // qMain.push(res);
    return qMain.back();
  }

  bool empty() { return qMain.empty(); }
};
int main() { return 0; }