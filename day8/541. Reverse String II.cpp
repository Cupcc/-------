/**
 * @Date: 2023 Nov 23
 * @Time: 23:56
 * @Author: Chris
 * @Desc: 541. Reverse String II
 * @Link: https://leetcode.cn/problems/reverse-string-ii/
 **/
#include <iostream>

using namespace std;

class Solution {
 public:
  void reverseSubstr(string& s, int start, int end) {
    int low = start, high = end;
    while (low < high) {
      s[low] ^= s[high];
      s[high] ^= s[low];  // b <= b ^ (a ^ b)
      s[low] ^= s[high];  // a <= (a ^ b) ^ a
      low++;
      high--;
    }
  }
  string reverseStr(string s, int k) {
    int index = 0;
    while (index < s.size()) {
      int right = index + k - 1 < s.size() ? index + k - 1 : s.size() - 1;
      reverseSubstr(s, index, right);
      index += 2 * k;
    }
    return s;
  }
};
int main() { return 0; }