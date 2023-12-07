/**
 * @Date: 2023 Dec 07
 * @Time: 11:10
 * @Author: Chris
 * @Title: 226.Invert Binary Tree
 * @Link: https://leetcode.cn/problems/invert-binary-tree/description/
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
  TreeNode* invertTree(TreeNode* root) {
    // 按层次左右子节点交换
    queue<TreeNode*> que;
    if (root) que.emplace(root);
    while (!que.empty()) {
      uint_fast16_t size = que.size();
      while (size--) {
        TreeNode* cur = que.front();
        que.pop();
        TreeNode* tmp = cur->left;
        cur->left = cur->right;
        cur->right = tmp;
        if (cur->left) que.emplace(cur->left);
        if (cur->right) que.emplace(cur->right);
      }
    }
    return root;
  }
};

int main() {
  // Create a sample binary tree to test the invertTree function
  TreeNode* root =
      new TreeNode{1,
                   new TreeNode{2, new TreeNode{4, nullptr, nullptr},
                                new TreeNode{5, nullptr, nullptr}},
                   new TreeNode{3, new TreeNode{6, nullptr, nullptr},
                                new TreeNode(7, nullptr, nullptr)}};

  Solution solution;

  // Test the invertTree function
  root = solution.invertTree(root);

  delete root;  // Release memory after testing

  return 0;
}