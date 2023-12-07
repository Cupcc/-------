/**
 * @Date: 2023 Dec 07
 * @Time: 10:29
 * @Author: Chris
 * @Title: 107. Binary Tree Level Order Traversal II
 * @Link:
 *https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/
 **/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode*> que;
    if (root) que.emplace(root);
    while (!que.empty()) {
      vector<int> layer;
      size_t size = que.size();
      for (uint_fast16_t i = 0; i < size; ++i) {
        TreeNode* node = que.front();
        que.pop();
        layer.emplace_back(node->val);
        if (node->left) que.emplace(node->left);
        if (node->right) que.emplace(node->right);
      }
      result.emplace_back(layer);
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() { return 0; }