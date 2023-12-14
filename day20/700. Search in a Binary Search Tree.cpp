/**
 * @Date: 2023 Dec 14
 * @Time: 22:22
 * @Author: Chris
 * @Title: 700. Search in a Binary Search Tree
 * @Link:
 *https://leetcode.cn/problems/search-in-a-binary-search-tree/description/
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
  // binary serach root (BST)
  TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) return root;
    return searchBST(val < root->val ? root->left : root->right, val);
  }
};
int main() { return 0; }