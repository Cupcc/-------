/**
 * @Date: 2023 Dec 22
 * @Time: 22:59
 * @Author: Chris
 * @Title: 93. Restore IP Addresses
 * @Link: https://leetcode.cn/problems/restore-ip-addresses/
 **/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
  vector<string> res;
  // [start, end]
  bool isValid(const string &s, int start, int end) {
    if (start > end) return false;
    // 0 可以，0开头不行
    if (s[start] == '0' && start != end) return false;
    int num = 0;
    for (int i = start; i <= end; ++i) {
      if (s[i] > '9' || s[i] < '0') return false;
      num = num * 10 + (s[i] - '0');
      if (num > 255) return false;
    }
    return true;
  }
  void backtracking(string &s, int startIndex, int pointNum) {
    if (pointNum == 3) {
      if (isValid(s, startIndex, s.size() - 1)) {
        res.push_back(s);
      }
      return;
    }
    for (int i = startIndex; i < s.size(); ++i) {
      //不合法这一层直接跳过，不用再判断了
      if (!isValid(s, startIndex, i)) break;

      s.insert(s.begin() + i + 1, '.');
      // 因为插入了一个点！所以+2
      backtracking(s, i + 2, pointNum + 1);
      // 在指定的插入位置删'.'
      s.erase(s.begin() + i + 1);
    }
  }

 public:
  vector<string> restoreIpAddresses(string s) {
    if (s.size() < 4 || s.size() > 12) return res;
    backtracking(s, 0, 0);
    return res;
  }
};
int main() { return 0; }