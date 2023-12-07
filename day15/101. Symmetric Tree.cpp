/**
 * @Date: 2023 Dec 07
 * @Time: 12:13
 * @Author: Chris
 * @Title: 101. Symmetric Tree
 * @Link: https://leetcode.cn/problems/symmetric-tree/description/
 * @Notes:    
 *  // 内侧和内侧对比，外侧和外侧对比
    // 左子树的右边 vs. 右子树的左边
    // 左子树的左边 vs. 右子树的右边
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
class Solution2 {
 public:
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    queue<TreeNode*> que;
    que.emplace(root->left);
    que.emplace(root->right);

    while (!que.empty()) {
      TreeNode* leftNode = que.front();
      que.pop();
      TreeNode* rightNode = que.front();
      que.pop();
      if (!leftNode && !rightNode)
        continue;
      else if (!leftNode || !rightNode || leftNode->val != rightNode->val)
        return false;

      // 外侧
      que.emplace(leftNode->left);
      que.emplace(rightNode->right);

      // 内侧
      que.emplace(leftNode->right);
      que.emplace(rightNode->left);
    }
    return true;
  };

  class Solution {
    // 内侧和内侧对比，外侧和外侧对比
    // 左子树的右边 vs. 右子树的左边
    // 左子树的左边 vs. 右子树的右边
   public:
    bool compare(TreeNode* left, TreeNode* right) {
      // 包含空的情况
      // 不包括空的情况
      if (left == nullptr and right != nullptr)
        return false;
      else if (left != nullptr and right == nullptr)
        return false;
      else if (!left && !right)
        return true;
      else if (left->val != right->val)
        return false;
      else
        return compare(left->right, right->left) &&
               compare(left->left, right->right);
    }

    bool isSymmetric(TreeNode* root) {
      if (!root)
        return true;
      else
        return compare(root->left, root->right);
    }
  };
  int main() { return 0; }