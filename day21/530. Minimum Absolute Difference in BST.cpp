/**
 * @Date: 2023 Dec 15
 * @Time: 20:30
 * @Author: Chris
 * @Title: 530. Minimum Absolute Difference in BST
 * @Link:
 *https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/
 **/
#include <iostream>
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
  // 二叉搜索树，有序列的
  // 中序,非降序序列
  // 使用迭代器写法
  vector<int> vec;
  void traversal(TreeNode* root) {
    if (root == nullptr) return;
    if (root->left) traversal(root->left);
    vec.emplace_back(root->val);
    if (root->right) traversal(root->right);
  }
  int getMinimumDifference(TreeNode* root) {
    vec.clear();
    int min = INT_MAX;
    traversal(root);
    auto it = vec.begin();
    while (++it != vec.end()) {
      int diff = *it - *(it - 1);
      min = diff < min ? diff : min;
    }
    return min;
  }
};
int main() { return 0; }