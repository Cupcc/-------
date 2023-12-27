/**
 * @Date: 2023 Dec 27
 * @Time: 23:43
 * @Author: Chris
 * @Title: 509.Fibonacci Number
 * @Link: https://leetcode.cn/problems/fibonacci-number/description/
 **/
#include <iostream>

using namespace std;
class Solution {
 public:
  int fib(int n) { return n < 2 ? n : fib(n - 1) + fib(n - 2); }
};
int main() { return 0; }