/**
 * @Date: 2023 Dec 18
 * @Time: 22:52
 * @Author: Chris
 * @Title: 538. Convert BST to Greater Tree
 * @Link: https://leetcode.cn/problems/convert-bst-to-greater-tree/description/
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
/// @brief greater sum tree 累加树，从后往前累加
class Solution {
 private:
  int pre = 0;
  // 从后往前累加，所以需要从后向前遍历。
  // 就是 右 -> 根 -> 左
  void traversal(TreeNode* cur) {
    if (cur == nullptr) return;
    traversal(cur->right);
    cur->val += pre;
    pre = cur->val;  // 所有的节点都是累加形成的，所以这是一个累加值
    traversal(cur->left);
  }

 public:
  TreeNode* convertBST(TreeNode* root) {
    traversal(root);
    return root;
  }
};
int main() { return 0; }