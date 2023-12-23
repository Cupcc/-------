/**
 * @Date: 2023 Dec 23
 * @Time: 09:29
 * @Author: Chris
 * @Title: 139. Word Break
 * @Link: https://leetcode.cn/problems/word-break/description/
 **/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  //  1. 问题分析：
  //   物品是什么？    字典
  //   背包容量是什么？ 字符串的长度
  //   dp[j] 是什么？ 字符串长度为j时，是否能被字典分割。
  //  2. 问题判断：
  //  什么背包类型？             什么问题类型？
  //  物品可重复——>完全背包      物品出现顺序可颠倒->排列问题
  //  3. 递推公式：状态转移，由上一状态推导当前状态
  //       if dp[i-word.size()] == true
  //             and s.substr() == word
  //       then dp[i] == true;
  //  4. 初始化， false, dp[0] = true 作为递归到初始
  //  5. 遍历顺序：外背包内物品，从前向后
  //  6. 边界处理，防止溢出
  bool wordBreak(string s, vector<string>& wordDict) {
    int len = s.size();
    vector<bool> dp(len + 1, false);
    dp[0] = true;
    for (int i = 0; i <= len; ++i) {
      for (const string& word : wordDict) {
        if ((i >= word.size() && dp[i - word.size()] == true)
            && (s.substr(i - word.size(), word.size()) == word)) {
          dp[i] = true;
        }
      }
    }
    return dp[len];
  }
};

class Solution2 {
 public:
  // 物品：每一个单词， 背包容量：s字符串的长度
  // 排列问题：给定{A,B}序列，可以出现[B,A]顺序，
  //         即选完后面元素，可以继续选前面的元素。
  // dp[i]含义: 长度为j的字符串能是否能被正确拆分
  // 递推公式:  由当前状态推导下一个状态
  //      如果dp[i]不能被拆分 跳过
  //      如果dp[i]能被拆分，且s[i, i+word.size())这一段在字典中。
  //                       那么dp[i+word.size()]= true;
  // 初始化： dp[0] =true, 其他全为false
  // 遍历顺序: 可重复->完全背包，从前向后
  // 内外层顺序：排列问题 -> 外背包，内物品。
  // 对于每一个背包容量，询问是否能容纳该物品
  bool wordBreak(string s, vector<string>& wordDict) {
    int len = s.size();
    vector<bool> dp(len + 1, false);
    dp[0] = true;
    for (int i = 0; i <= len; ++i) {
      if (dp[i] == false) continue;
      for (const string& word : wordDict) {
        if (i + word.size() <= len && s.substr(i, word.size()) == word) {
          dp[i + word.size()] = true;
        }
      }
    }
    return dp[len];
  }
};

int main() { return 0; }