/**
 * @Date: 2023 Nov 25
 * @Time: 00:43
 * @Author: Chris
 * @Desc: 28.Find the Index of the First Occurrence in a String
Given two strings needle and haystack, return the index of the first occurrence
of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.


Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

 * @Link:
 *https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 **/
// kmp 算法
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  //计算 next 数组
  vector<int> getNext(string needle) {
    int m = needle.size();
    int index = 0;
    vector<int> lps(m);

    // 相等的相同前后缀，
    // 前缀不包括最后一个
    // 后缀不包括第一个，所以从第 2 位置开始
    for (int i = 1; i < m;) {
      if (needle[i] == needle[index]) {
        lps[i] = index + 1;
        index++;
        i++;
      } else {
        if (index != 0) {
          index = lps[index - 1];
        } else {
          lps[i] = 0;
          i++;
        }
      }
    }
    return lps;
  }

  // KMP算法
  int strStr(string haystack, string needle) {
    // n 文本串长度， m 模式串长度
    int n = haystack.size();
    int m = needle.size();
    if (m == 0) return 0;
    vector<int> lps = getNext(needle);

    // i 匹配文本串，j 匹配模式串
    int i = 0;  // 匹配 haystack 的位置
    int j = 0;  // 匹配 needle 的位置
    while (i < n) {
      // 相同，匹配指针前进 1 步
      if (haystack[i] == needle[j]) {
        i++;
        j++;
      }
      // 模式串完全匹配成功
      if (j == m)
        return i - j;
      // 没有完全匹配成功
      // 1. 
      else if (i < n && haystack[i] != needle[j]) {
        if (j != 0) // 模式串匹配了几个，不在第一个位置
          j = lps[j - 1]; // 模式串回退到前缀的末尾
        else // 模式串一个都没成功匹配
          i++; // 移动文本串，模式串不动，继续在第一个位置
      }
    }
    return -1;
  }
  int strStr2(string haystack, string needle) {
    //  简单一个个匹配
    if (needle.empty()) return 0;
    int m = haystack.size(), n = needle.size();
    if (m < n) return -1;
    for (int i = 0; i <= m - n; i++) {
      int j = 0;
      for (; j < n; j++) {
        if (haystack[i + j] != needle[j]) break;
      }
      if (j == n) return i;
    }
    return -1;
  }
  /*   int strStr(string haystack, string needle) {
      size_t found = haystack.find(needle);
      if (found != std::string::npos) return found;

      return -1;
    } */
};


int main() { return 0; }

