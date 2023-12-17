/**
 * @Date: 2023 Dec 15
 * @Time: 21:52
 * @Author: Chris
 * @Title: 235. Lowest Common Ancestor of a Binary Search Tree
 * @Link:
 *https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
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
  // 从上向下去递归遍历，
  // 第一次遇到 cur节点是数值在[q, p]区间中，那么cur就是 q和p的最近公共祖先。
  // 比较时：不知道p和q谁大，所有都需要比较
  TreeNode* traversal(TreeNode* node, TreeNode* p, TreeNode* q) {
    if (node == nullptr) return node;

    // node>p,q 那么往左边寻找
    if (node->val > p->val && node->val > q->val) {
      TreeNode* left = traversal(node->left, p, q);
      if (left != nullptr) return left;
    }
    // node<p,q 那么往右边搜索
    if (node->val < p->val && node->val < q->val) {
      TreeNode* right = traversal(node->right, p, q);
      if (right) return right;
    }
    // 在 p,q之间，找到了！！！
    return node;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return traversal(root, p, q);
  }
};
int main() { return 0; }