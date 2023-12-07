/**
 * @Date: 2023 Dec 07
 * @Time: 16:33
 * @Author: Chris
 * @Title: 111. Minimum Depth of Binary Tree
 * @Link: https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
 **/
#include <algorithm>
#include <iostream>
#include <queue>
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
  // level order 如果该节点没有左右孩子，即为最小高度。
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    int depth = 0;
    queue<TreeNode*> que;
    que.emplace(root);
    while (!que.empty()) {
      depth++;
      uint_fast16_t size = que.size();
      while (size--) {
        TreeNode* node = que.front();
        que.pop();
        if (!node->left and !node->right) return depth;
        if (node->left) que.emplace(node->left);
        if (node->right) que.emplace(node->right);
      }
    }
    return depth;
  }
};

class Solution2 {
 public:
  // 后序遍历，根后处理，先计算子树的高度
  int getMinDepth(TreeNode* node) {
    if (!node) return 0;
    int leftDepth = getMinDepth(node->left);    // 左
    int rightDepth = getMinDepth(node->right);  // 右
                                                // 根

    // 一个子树为空
    // 左空，右不空
    // 如果不处理一个子树为空的情况，那么会返回虚假的最小深度
    // 最小高度为，叶子结点的深度，即该节点没有左孩子，也没有有孩子
    if (node->left == nullptr && node->right != nullptr) {
      return 1 + rightDepth;
    }
    if (node->left != nullptr and node->right == nullptr) {
      return 1 + leftDepth;
    } else  // 两个子树都不空或者都空
      return 1 + min(leftDepth, rightDepth);
  }
  int minDepth(TreeNode* root) {
    return getMinDepth(root);
  }
};

int main() { return 0; }