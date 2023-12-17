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
#define DEFER(func) Defer CAT(defer_, __LINE__)([&]() { func; })

void deleteTreeNode(TreeNode* node) { delete node; }

class Solution {
 public:
  // 如果需要node节点，那么
  // 把node的左子树，插入到右子树的最左侧，
  TreeNode* deleteNode(TreeNode* root, int key) {
    // 空
    // 不空==val：删除该节点
    // 返回： 1.左子树空返回右子树
    //       2. 右子树空 返回左子树
    //       3. 子树为空，返回nullptr
    //       4. 都不空，将左子树插入到右子树的最左侧。
    if (root == nullptr) return root;
    if (root->val == key) {
      TreeNode* retNode;
      DEFER(deleteTreeNode(root));
      if (root->left == nullptr) {
        retNode = root->right;
        return retNode;
      }
      if (root->right == nullptr) {
        retNode = root->left;
        return retNode;
      }
      if (!root->left && !root->right) {
        return nullptr;
      } else {
        TreeNode* cur = root->right;
        while (cur->left != nullptr) {
          cur = cur->left;
        }
        cur->left = root->left;
        retNode = root->right;
        return retNode;
      }
    }
    if (key < root->val) root->left = deleteNode(root->left, key);
    if (key > root->val) root->right = deleteNode(root->right, key);
    return root;
  }
};

int main() { return 0; }