/**
 * @Date: 2023 Nov 30
 * @Time: 21:37
 * @Author: Chris
 * @Desc: 20. Valid Parentheses
 * @Link: https://leetcode.cn/problems/valid-parentheses/description/
 **/
#include <iostream>
#include <stack>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    if ((s.size() & 1) == 1) return false;
    stack<char> st;
    for (const auto ch : s) {
      if (ch == '{')
        st.emplace('}');
      else if (ch == '[')
        st.emplace(']');
      else if (ch == '(')
        st.emplace(')');
      else if (st.empty() || st.top() != ch)
        return false;
      else
        st.pop();
    }
    // 最后判断 st是否为空，空了才是对的。
    return st.empty();
  }
};
int main() { return 0; }