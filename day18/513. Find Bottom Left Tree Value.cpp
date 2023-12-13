/**
 * @Date: 2023 Dec 12
 * @Time: 15:45
 * @Author: Chris
 * @Title: 513. Find Bottom Left Tree Value
 * @Link: https://leetcode.cn/problems/find-bottom-left-tree-value/description/
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
  // 寻找深度最大的当中，排在最左边的，不一定是左子树
  int maxDepth = INT_MIN;
  int result;
  void traversal(TreeNode* root, int depth) {
    if (root->left == nullptr && root->right == nullptr) {
      if (depth > maxDepth) {  // 中
        maxDepth = depth;
        result = root->val;
      }
      return;
    }
    if (root->left) {
      traversal(root->left, depth + 1); //回溯
    }
    if (root->right) {
      traversal(root->right, depth + 1); 
    }
    return;
  }
  int findBottomLeftValue(TreeNode* root) {
    traversal(root, 0);
    return result;
  }
};

class Solution2 {
 public:
  // 迭代法
  // 最后底层第一个节点。
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != nullptr) que.emplace(root);
    int result = 0;
    while (!que.empty()) {
      int size = que.size();
      for (size_t i = 0; i < size; i++) {
        TreeNode* node = que.front();
        que.pop();
        if (i == 0) result = node->val;
        if (node->left) que.emplace(node->left); 
        if (node->right) que.emplace(node->right);
      }
    }
    return result;
  }
};
int main() { return 0; }
