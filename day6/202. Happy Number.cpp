/**
 * @Date: 2023 Nov 20
 * @Time: 00:33
 * @Author: Chris
 * @Desc: 202. Happy Number
 * @Link: https://leetcode.cn/problems/happy-number/description/
 **/
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int getSumofSquare(int n) {
    int sum = 0;
    while (n) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
    return sum;
  }
  bool isHappy(int n) {
    unordered_set<int> set;
    while (1) {
      int sum = getSumofSquare(n);
      if (sum == 1) {
        return true;
      }
      // 集合中存在 sum，陷入循环
      if (set.find(sum) != set.end()) {
        return false;
      } else {
        set.insert(sum);
      }
      // 更新 n
      n = sum;
    }
  }
};
int main() { return 0; }