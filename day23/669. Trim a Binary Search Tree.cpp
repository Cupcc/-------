/**
 * @Date: 2023 Dec 18
 * @Time: 22:26
 * @Author: Chris
 * @Title: 669. Trim a Binary Search Tree
 * @Link: https://leetcode.cn/problems/trim-a-binary-search-tree/description/
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
 // 如果在[low,high]之内，就正常返回root自身本节点
 // 如果超过了， root->val > high 返回root的左孩子
 //  root->val < low  返回root的右孩子
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (root == nullptr) return nullptr;
    // 返回本节点的右孩子
    if (root->val < low) {
      TreeNode* right = trimBST(root->right, low, high);
      return right;
    }
    // 返回本节点的左孩子。
    if (root->val > high) {
      TreeNode* left = trimBST(root->left, low, high);
      return left;
    }
    // 继续递归遍历这个树
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    // 返回本节点
    return root;
  }
};
int main() { return 0; }