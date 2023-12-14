/**
 * @Date: 2023 Dec 14
 * @Time: 22:06
 * @Author: Chris
 * @Title: 617. Merge Two Binary Trees
 * @Link: https://leetcode.cn/problems/merge-two-binary-trees/description/
 **/
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
  /// @brief 前中后遍历都可以
  /// @param root1
  /// @param root2
  /// @return
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    // 如果遇到为空，直接返回另一个树的子节点的所有分支即可，不再往下递归。
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;
    // 不改变两个树的结构
    TreeNode* root = new TreeNode();
    root->val = root1->val + root2->val;                   // 根
    root->left = mergeTrees(root1->left, root2->left);     // 左
    root->right = mergeTrees(root1->right, root2->right);  // 右
    return root;
  }
};
int main() { return 0; }