/**
 * @Date: 2023 Dec 15
 * @Time: 21:17
 * @Author: Chris
 * @Title: 236. Lowest Common Ancestor of a Binary Tree
 * @Link:
 *https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
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
  // 回溯，从底层向上遍历。
  // 后序遍历
  // 询问子树有没有pq的公共节点，
  // 1. 左子树有，右子树有，那么返回root, root也是左右子树的公共节点。
  // 2. 左子树有公共节点，右子树没有，那么左子树就是最近的公共节点，返回左子树。
  // 3. 同理 右子树有，返回右子树
  // 4. 左子树没有，右子树没有，返回nullptr或者返回左右子树，反正都是nullptr
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 最少有两个节点，如果少一个，那么root就是公共节点
    if (!root || root == p || root == q) return root;
    TreeNode* left_common_node = lowestCommonAncestor(root->left, p, q);
    TreeNode* right_common_node = lowestCommonAncestor(root->right, p, q);
    if (left_common_node && right_common_node) return root;
    if (!left_common_node && right_common_node) return right_common_node;
    if (left_common_node && !right_common_node) return left_common_node;
    return nullptr;  // 左右都为空
  }
};
int main() { return 0; }