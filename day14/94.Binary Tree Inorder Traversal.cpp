/**
 * @Date: 2023 Dec 05
 * @Time: 23:37
 * @Author: Chris
 * @Desc: 94.Binary Tree Inorder Traversal
 * @Link:
 *https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
 **/
#include <iostream>
#include <stack>
#include <string>
#include <utility>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
private:
  vector<int> res;

public:
  void inorder(TreeNode *root) {
    if (!root)
      return;
    inorder(root->left);
    res.emplace_back(root->val);
    inorder(root->right);
  }
  vector<int> inorderTraversal(TreeNode *root) {
    inorder(root);
    return res;
  }
};

class Solution2 {
  // 迭代法
public:
  vector<int> inorderTraversal(TreeNode *root) {
    // left, root, right
    // push order: right, root, left.
    // 先把自己弹出来，按照右-根-左的顺序入站，在根后面加一个nullptr进行标记。
    vector<int> res;
    if (!root)
      return res;
    stack<TreeNode *> s;
    s.emplace(root);

    while (!s.empty()) {
      TreeNode *node = s.top();
      s.pop();

      if (node) {
        if (node->right)
          s.emplace(node->right); // 右
        s.emplace(node);          // 根
        s.emplace(nullptr);       // 标记根
        if (node->left)           // 左
          s.emplace(node->left);
      } else {
        res.emplace_back(s.top()->val);
        s.pop();
      }
    }
    return res;
  }
};

class Solution3 {
  // 迭代法
public:
  vector<int> inorderTraversal(TreeNode *root) {
    // left, root, right
    // 左子树全入栈，然后依次弹出，和后序类似，不过后序需要标记有子节点是否被加入过
    vector<int> res;
    if (!root)
      return res;
    stack<TreeNode *> s;
    TreeNode *cur = root;

    // 栈可能弹空了，换成 root 的右子树
    while ( cur or !s.empty()) {
      if (cur) {
        s.emplace(cur); // 左
        cur = cur->left;
      } else {
        cur = s.top();
        s.pop();
        res.emplace_back(cur->val); // 中
        cur = cur->right;           // 右
      }
    }
    return res;
  }
};

int main() { return 0; }