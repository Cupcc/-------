/**
 * @Date: 2023 Dec 07
 * @Time: 09:58
 * @Author: Chris
 * @Desc: 102. Binary Tree Level Order Traversal
 * @Link: https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 **/
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
 // level Order Traversal
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty()) {
      size_t size = q.size();
      vector<int> layer;
      for (size_t i = 0; i < size; i++) {
        TreeNode* cur = q.front();
        q.pop();
        layer.emplace_back(cur->val);
        if (cur->left) q.emplace(cur->left);
        if (cur->right) q.emplace(cur->right);
      }
      res.emplace_back(layer);
    }
    return res;
  }
};

int main() { return 0; }