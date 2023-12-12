/**
 * @Date: 2023 Dec 07
 * @Time: 17:25
 * @Author: Chris
 * @Title: 110. Balanced Binary Tree
 * @Link: https://leetcode.cn/problems/balanced-binary-tree/description/
 **/
#include <stdlib.h>

#include <iostream>
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
class Solution {
 public:
  // 求高度，后序
  int getHeight(TreeNode* node) {
    if (node == nullptr) return 0;
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    if (leftHeight == -1 or rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1)
      return -1;
    else
      return 1 + max(leftHeight, rightHeight);
  }
  bool isBalanced(TreeNode* root) {
    if (getHeight(root) == -1)
      return false;
    else
      return true;
  }
};
int main() { return 0; }