/**
 * @Date: 2023 Dec 07
 * @Time: 10:48
 * @Author: Chris
 * @Title: 199. Binary Tree Right Side View
 * @Link: https://leetcode.cn/problems/binary-tree-right-side-view/description/
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
  vector<int> rightSideView(TreeNode* root) {
    // 每一层的最右边
    vector<int> result;
    queue<TreeNode*> que;
    if (root) que.emplace(root);
    while (!que.empty()) {
      uint_fast16_t size = que.size();
      TreeNode* node=nullptr;
      while (size--) {
        node = que.front();
        que.pop();
        if (node->left) que.emplace(node->left);
        if (node->right) que.emplace(node->right);
      }
      result.emplace_back(node->val);
    }

    return result;
  }
};
int main() { return 0; }