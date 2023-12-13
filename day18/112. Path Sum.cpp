/**
 * @Date: 2023 Dec 13
 * @Time: 13:47
 * @Author: Chris
 * @Title: 112. Path Sum
 * @Link: https://leetcode.cn/problems/path-sum/description/
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

// 简化版
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    // 当前节点还没有减去root->val
    if (!root->left && !root->right and targetSum == root->val) {
      return true;
    }
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
  }
};

class Solution {
 public:
  bool traversal(TreeNode* cur, int count) {
    if (!cur) return false;
    // 注意cur->val此时没有减去！
    if (!cur->left && !cur->right) {
      if (count == cur->val)
        return true;
      else
        return false;
    }
    if (traversal(cur->left, count - cur->val)) return true;
    if (traversal(cur->right, count - cur->val)) return true;
    return false;
  }
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    return traversal(root, targetSum);
  }
};
int main() { return 0; }
