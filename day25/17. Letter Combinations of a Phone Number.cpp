/**
 * @Date: 2023 Dec 19
 * @Time: 11:03
 * @Author: Chris
 * @Title: 17. Letter Combinations of a Phone Number
 * @Link:
 *https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 **/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const string letterMap[10] = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};

// 索引和字符串一起进行回溯。
class Solution {
 private:
  vector<string> res;
  void backtracking(const string &digits, int &&index, const string &s) {
    if (index == digits.size()) {
      res.emplace_back(s);
      return;  // 回溯
    }
    int digit = digits[index] - '0';
    for (const auto c : letterMap[digit]) {
      backtracking(digits, index + 1, s + c);
    }
  }

 public:
  vector<string> letterCombinations(string digits) {
    // 注意边缘处理 digits="", 返回 [] 而不是[""]
    if (digits.size() == 0) return res;
    backtracking(digits, 0, "");
    return res;
  }
};

class Solution {
 private:
  vector<string> res;
  string path;

  /// @brief
  /// @param digits 按键字符串"2341"
  /// @param cur_index  上面这个字符串遍历的位置
  void backtracking(string digits, int cur_index) {
    if (cur_index == digits.size()) {
      res.emplace_back(path);
      return;
    }
    // 将index按键字符串转换成数字
    int digit = digits[cur_index] - '0';
    string letters = letterMap[digit];
    for (const auto letter : letters) {
      // 这里索引和字符都进行回溯，
      // 两者的个数都为1. 所以可以合并成一个！
      path.push_back(letter);
      backtracking(digits, cur_index + 1);
      path.pop_back();
    }
  }

 public:
  vector<string> letterCombinations(string digits) {
    // 注意边缘处理 "" 返回 [] 而不是[""]
    if (digits.size() == 0) return res;
    backtracking(digits, 0);
    return res;
  }
};
int main() { return 0; }