/**
 * @Date: 2023 Dec 07
 * @Time: 17:10
 * @Author: Chris
 * @Title: 222.Count Complete Tree Nodes
 * @Link: https://leetcode.cn/problems/count-complete-tree-nodes/description/
 **/
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
  // 后序遍历
  // 空间： O(log n) 树的高度
  // 时间: O(n) 每个节点计算一次
  int getNodeNums(TreeNode* cur) {
    if (cur == nullptr) return 0;
    int leftNums = getNodeNums(cur->left);
    int rightNums = getNodeNums(cur->right);
    return leftNums + rightNums + 1;
  }
  int countNodes(TreeNode* root) { return getNodeNums(root); }
};

class Solution {
 public:
  // 迭代
  // level order traversal
  int countNodes(TreeNode* root) {
    if (!root) return 0;
    int ans = 0;
    queue<TreeNode*> que;
    que.emplace(root);
    while (!que.empty()) {
      int size = que.size();
      while (size--) {
        TreeNode* node = que.front();
        que.pop();
        ans++;
        if (node->left) que.emplace(node->left);
        if (node->right) que.emplace(node->right);
      }
    }
    return ans;
  }
};

int main() { return 0; }