/**
 * @Date: 2023 Dec 19
 * @Time: 18:15
 * @Author: Chris
 * @Title: 131. Palindrome Partitioning
 * @Link: https://leetcode.cn/problems/palindrome-partitioning/description/
 **/
#include <iostream>
#include <vector>
using namespace std;
/// @brief 切割问题也属于组合问题，组合就回溯
// 不断的分割，确保已经分割的都是回文字符串，那么如果能分割完则成功全部找到！
//  加了一个判断回文字符串的功能。
class Solution {
 private:
  vector<vector<string>> res;
  vector<string> path;

  bool isPalindrome(const string& s, int start, int end) {
    // 双指针法
    for (int i = start, j = end; i < j; ++i, --j) {
      if (s[i] != s[j]) return false;
    }
    return true;
  }
  void backtracking(const string& s, int startIndex) {
    if (startIndex == s.size()) {
      res.push_back(path);
      return;
    }
    for (size_t i = startIndex; i < s.size(); ++i) {
      if (isPalindrome(s, startIndex, i)) {
        string str = s.substr(startIndex, i - startIndex + 1);
        path.push_back(str);
        backtracking(s, i + 1);
        path.pop_back();
      }
    }
  }

 public:
  vector<vector<string>> partition(string s) {
    backtracking(s, 0);
    return res;
  }
};

vector<vector<bool>> isPalindrome;
void computePalindrome(const string& s) {
  // isPalindrome[i][j] 代表 s[i:j](双边包括)是否是回文字串
  isPalindrome.resize(
      s.size(),
      vector<bool>(s.size(), false));  // 根据字符串s, 刷新布尔矩阵的大小
  for (int i = s.size() - 1; i >= 0; i--) {
    // 需要倒序计算, 保证在i行时, i+1行已经计算好了
    for (int j = i; j < s.size(); j++) {
      // 一些细节处理
      if (j == i) {  // 一个字符的情况
        isPalindrome[i][j] = true;
      } else if (j - i == 1) {  // 2个字符的情况
        isPalindrome[i][j] = (s[i] == s[j]);
      } else {
        isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
      }
    }
  }
}

int main() { return 0; }
