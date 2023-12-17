/**
 * @Date: 2023 Dec 17
 * @Time: 21:29
 * @Author: Chris
 * @Title: 701.Insert into a Binary Search Tree
 * @Link:
 *https://leetcode.cn/problems/insert-into-a-binary-search-tree/description/
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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    // 需要在可以插入的空位置插入。
    if (root == nullptr) {
      TreeNode* node = new TreeNode(val);
      return node;
    }
    // 只要找到位置就插入，有位置就插入就返回。
    // 用left保持原结构不变，或者接住新的节点。
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    // 用right保持结构不变，或者接住新的节点
    if (val > root->val) root->right = insertIntoBST(root->right, val);
    // 保持结构不变
    return root;
  }
};
int main() { return 0; }