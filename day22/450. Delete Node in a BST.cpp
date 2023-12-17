/**
 * @Date: 2023 Dec 17
 * @Time: 22:47
 * @Author: Chris
 * @Title: 450. Delete Node in a BST
 * @Link: https://leetcode.cn/problems/delete-node-in-a-bst/description/
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
class Defer {
 public:
  Defer(std::function<void()> func) : func_(func) {}
  ~Defer() { func_(); }

 private:
  std::function<void()> func_;
};

#define CAT(x, y) (x##y)
#define CAT_INTER(x, y) CAT(x, y)
#define DEFER(func) Defer CAT_INTER(defer_, __LINE__)([&]() { func; })

void deleteTreeNode(TreeNode* node) { delete node; }

class Solution {
 public:
  /// @brief
  // 空  返回root
  // 不空==val：删除该节点, 判断左右孩子
  /// @param root
  /// @param key
  /// @return
  // 返回： 1. 左右孩子都不空，将左子树插入到右子树的最左侧。
  //       2. 左子树空，返回右子树
  //       2. 右子树空 返回左子树
  //       3. 子树为空，返回nullptr
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;
    if (root->val == key) {
      TreeNode* retNode;
      DEFER(deleteTreeNode(root));
      if (root->left && root->right) {
        TreeNode* cur = root->right;
        while (cur->left) cur = cur->left;
        cur->left = root->left;
        retNode = root->right;
      } else
        retNode = root->left ? root->left : root->right;
      return retNode;
    }
    if (key < root->val) root->left = deleteNode(root->left, key);
    if (key > root->val) root->right = deleteNode(root->right, key);
    return root;
  }
};

int main() { return 0; }