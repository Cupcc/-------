/**
 * @Date: 2023 Nov 10
 * @Time: 18:43
 * @Author: Chris
 * @Desc: 59. Spiral Matrix II
 * Given a positive integer n, generate an n x n matrix filled
 * with elements from 1 to n2 in spiral order.
 * Tips:
 * 1. simulation
 * 2. 循环不变量
 **/
#include <iostream>

using namespace std;
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    // [left, right)
    // n * n initialization
    vector<vector<int>> res(n, vector<int>(n, 0));
    int startx = 0, starty = 0;
    int loop = n / 2;  // 转几圈
    int mid = n / 2;   // matrix center
    int count = 1;     // the last cell
    int offset = 1;    // control the length of every side, 右边界缩小1位
    int i, j;
    while (loop--) {
      j = startx;
      j = starty;

      // 4个 for模拟旋转一圈
      for (j = starty; j < n - offset; j++) {
        res[startx][j] = count++;  // right
      }
      for (i = startx; i < n - offset; i++) {
        res[i][j] = count++;  // down
      }
      for (; j > starty; j--) {  // left
        res[i][j] = count++;
      }
      for (; i > startx; i--) {
        res[i][j] = count++;
      }
      // 下一圈，起始位置
      startx++;
      starty++;
      // 终止位置
      offset += 1;
    }
    // if n is odd, then fill the central cell with count.
    if (1 == n % 2) {
      res[mid][mid] = count;
    }
    return res;
  }
};
int main() { return 0; }