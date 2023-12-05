/**
 * @Date: 2023 Dec 05
 * @Time: 22:48
 * @Author: Chris
 * @Desc: 144. Binary Tree Preorder Traversal
 * @Link:
 *https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
 **/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  vector<int> res;

public:
  void preorder(TreeNode *root) {
    if (!root)
      return;
    res.emplace_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }

  vector<int> preorderTraversal(TreeNode *root) {
    preorder(root);
    return res;
  }
};

class Solution2 {
  vector<int> preorderTraversal(TreeNode *root) {
    // 使用栈维护
    // 先进后出
    // 所以 preorder, 先push(node->right), 后push(node->left)
    vector<int> res;
    stack<TreeNode *> s;
    if (root)
      s.push(root);
    while (!s.empty()) {
      TreeNode *node = s.top();
      s.pop();
      res.emplace_back(node->val);
      if (node->right)
        s.push(node->right);
      if (node->left)
        s.push(node->left);
    }
    return res;
  }
};

int main() { return 0; }