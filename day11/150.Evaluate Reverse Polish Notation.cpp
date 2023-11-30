/**
 * @Date: 2023 Nov 30
 * @Time: 22:13
 * @Author: Chris
 * @Desc: 150.Evaluate Reverse Polish Notation
 * @Link:
 *https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/
 **/
#include <gtest/gtest.h>

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  long long calculate(string op, long long x1, long long x2) {
    // 注意减法和除法
    if (op == "*") {
      return x1 * x2;
    } else if (op == "/") {
      return x2 / x1;
    } else if (op == "+") {
      return x1 + x2;
    } else if (op == "-") {
      return x2 - x1;
    }
    return 0;
  }

  int evalRPN(vector<string>& tokens) {
    stack<long long> st;
    for (string str : tokens) {
      if (str == "+" || str == "-" || str == "*" || str == "/") {
        long long num1 = st.top();
        st.pop();
        long long num2 = st.top();
        st.pop();

        st.push(calculate(str, num1, num2));
      } else {
        st.emplace(stoll(str));
      }
    }
    return st.top();
  }
};

class TestSolution : public ::testing::Test {
 protected:
  Solution solution;
};
TEST_F(TestSolution, TestEvalRPN) {
  vector<string> tokens1 = {"2", "1", "+", "3", "*"};
  EXPECT_EQ(solution.evalRPN(tokens1), 9);

  vector<string> tokens2 = {"4", "13", "5", "/", "+"};
  EXPECT_EQ(solution.evalRPN(tokens2), 6);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  return 0;
}