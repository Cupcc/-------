/**
 * @Date: 2023 Nov 30
 * @Time: 21:57
 * @Author: Chris
 * @Desc: 1047. Remove All Adjacent Duplicates In String
 * @Link:
 *https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
 **/
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  /*
  1. 如果栈空，直接入站
  2. 如果栈不空： 比较是否相同
        a. 不同，入站
        b. 相同，出栈，
   */

  string removeDuplicates(string s) {
    stack<char> st;
    if (s.size() <= 1) return s;
    for (const auto ch : s) {
      if (st.empty() || ch != st.top()) {
        st.emplace(ch);
      } else {
        st.pop();
      }
    }
    string res = "";
    while (!st.empty()) {
      res += st.top();
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
int main() { return 0; }