/**
 * @Date: 2023 Nov 23
 * @Time: 23:26
 * @Author: Chris
 * @Desc: 344. Reverse String
 * @Link: https://leetcode.cn/problems/reverse-string/
 **/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    // 异或符号 ^ XOR
    // 真值表 00->0,
    //        01->1,
    //        10->1,
    //        11->0
    // 性质:恒等律 p ^ 0 = p
    // 归零律 ： p ^ p = 0
    // ->自反律 p ^ p ^ t = t
    int low = 0, high = s.size() - 1;
    while (low < high) {
      s[low] ^= s[high];
      s[high] ^= s[low];  // b <= b ^ (a ^ b)
      s[low] ^= s[high];  // a <= (a ^ b) ^ a
      low++;
      high--;
    }
  }
} void reverseString(vector<char>& s) {
  int low = 0, high = s.size() - 1;
  while (low < high) {
    char tmp = s[high];
    s[high] = s[low];
    s[low] = tmp;
    low++;
    high--;
  }
}
}
;
int main() { return 0; }