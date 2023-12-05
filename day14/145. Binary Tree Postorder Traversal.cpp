/**
 * @Date: 2023 Dec 05
 * @Time: 23:07
 * @Author: Chris
 * @Desc: 145. Binary Tree Postorder Traversal
 * @Link:
 *https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
 **/
#include <iostream>
#include <stack>
#include <vector>

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
  void postorder(TreeNode *root) {
    if (!root)
      return;
    postorder(root->left);
    postorder(root->right);
    res.emplace_back(root->val);
  }
  vector<int> postorderTraversal(TreeNode *root) {
    postorder(root);
    return res;
  }
};

class Solution2 {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    // 顺序 left, right, root
// 需要保存前驱节点
    // 基本流程，一直压入左子节点到最深层，然后回退，进入右子节点，再压入所有的左子树。
    // 将所有的左子树压入栈中
    // 先处理栈顶，查看是否存在右子节点？
    //      不存在或者已经处理过，此时处理当前节点(相当于根节点)val加入数组！
    // 若存在且没处理过：进入右子树。
    // 重复压入左子树
    vector<int> res;
    if (root == nullptr)
      return res;

    stack<TreeNode *> s;
    TreeNode *p = root;
    TreeNode *pre = nullptr;

     // 栈可能弹空了，换成 root 的右子树
    while (p || !s.empty()) {
      while (p) {
        s.push(p);
        p = p->left;
      }
      p = s.top();
      if (p->right == nullptr or pre == p->right) {
        pre = p;
        res.emplace_back(p->val);
        s.pop();
        p = nullptr;
      } else {
        p = p->right;
      }
    }
    return res;
  }
};
int main() { return 0; }