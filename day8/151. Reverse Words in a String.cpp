/**
 * @Date: 2023 Nov 24
 * @Time: 23:21
 * @Author: Chris
 * @Desc: 151. Reverse Words in a String
 * @Link: https://leetcode.cn/problems/reverse-words-in-a-string/description/
 **/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
using namespace std;

class Solution {
 public:
  
  void removeExtraspace(string &s) {
    // remove extra spaces
    int slow = 0;
    size_t fast = 0;
    // trim front spaces
    while (s.size() > 0 && fast < s.size() && s[fast] == ' ') {
      fast++;
    }

    for (; fast < s.size(); fast++) {
      if (fast > 0 && s[fast] == ' ' && s[fast] == s[fast - 1]) {
        continue;
      }
      s[slow++] = s[fast++];
    }
    // trim end spaces
    // 此时slow 为end()位置,slow-1才是最后一个字符
    if (slow - 1 > 0 && s[slow - 1] == ' ') {
      s.resize(slow - 1);
    } else {
      s.resize(slow);
    }
    // 可以用三元表达式替代
    // s.resize(slow - 1 > 0 && s[slow - 1] == ' '? slow-1: slow);
  }
  void reverseString(string &s, int start, int end) {
    for (size_t i = start, j = end; i < j; i++, j--) {
      swap(s[i], s[j]);
    }
  }
  void removeExtraSpaces(string &s) {
    int slow = 0;
    for (size_t fast = 0; fast < s.size(); fast++) {
      if (s[fast] != ' ') {  // 删除所有的空格，非空格才处理
        if (slow != 0) s[slow++] = ' ';  // 先添加空格
        while (fast < s.size() && s[fast] != ' ') {
          // 一直到下一个空格
          s[slow++] = s[fast++];
        }
      }
    }
    s.resize(slow);
  }

  string reverseWords(string s) {
    removeExtraSpaces(s);
    //   1.整体反转，2.局部反转
    reverseString(s, 0, s.size() - 1);
    int start = 0;
    for (size_t i = 0; i <= s.size(); i++) {
      if (i == s.size() || s[i] == ' ') {  // 打到末尾或者，达到单词
        reverseString(s, start, i - 1);
        start = i + 1;  // 跳过了 1 个空格
      }
    }
    return s;
  }
};
int main() { return 0; }