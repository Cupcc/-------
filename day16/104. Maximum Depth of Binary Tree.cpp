/**
 * @Date: 2023 Dec 07
 * @Time: 16:06
 * @Author: Chris
 * @Title: 104. Maximum Depth of Binary Tree
 * @Link: https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
 **/
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution2 {
 public:
  // level order Traversal
  int maxDepth(TreeNode* root) {
    if(!root) return 0;
    int depth = 0;
    queue<TreeNode*> que;
    que.emplace(root);
    while (!que.empty()) {
      uint_fast16_t size = que.size();
      while (size--) {
        TreeNode* node = que.front();
        que.pop();
        if (node->left) que.emplace(node->left);
        if (node->right) que.emplace(node->right);
      }
      depth++;
    }
    return depth;
  }
};

class Solution {
 public:
  // root深度 = 左或右子树最大高度+1。
  // node == nullptr 高度为0.
  // 后序遍历，最后计算根。
  int getDepth(TreeNode* node) {
    if (node == nullptr) return 0;
    int leftDepth = getDepth(node->left);
    int rightDepth = getDepth(node->right);
    return 1 + max(leftDepth, rightDepth);
  }

  int maxDepth(TreeNode* root) { return getDepth(root); }
};
int main() { return 0; }