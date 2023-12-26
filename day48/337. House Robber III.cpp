/**
 * @Date: 2023 Dec 26
 * @Time: 11:10
 * @Author: Chris
 * @Title: 337. House Robber III
 * @Link: https://leetcode.cn/problems/house-robber-iii/description/
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

// housed are arranged in a shape of a binary tree.
class Solution {
 private:
  vector<int> robTree(TreeNode* cur) {
    // vector<int> 0为不偷，1为偷
    if (cur == nullptr) return vector<int>{0, 0};
    vector<int> left = robTree(cur->left);
    vector<int> right = robTree(cur->right);
    // 偷 子节点不能偷
    int rob_value = cur->val + left[0] + right[0];
    // 不偷，子节点可偷可不偷，二选一选择最大值！然后加起来
    int not_rob_value = max(left[0], left[1]) + max(right[0], right[1]);
    return {not_rob_value, rob_value};
  }

 public:
  int rob(TreeNode* root) {
    vector<int> dp = robTree(root);
    return max(dp[0], dp[1]);
  }
};

class Solution2 {
 private:
  // int数组实现
  void robTree(TreeNode* cur, int* res) {
    // res[2] 0为不偷，1为偷
    if (cur == nullptr) {
      res[0] = 0;
      res[1] = 0;
      return;
    }
    int left[2], right[2];
    robTree(cur->left, left);
    robTree(cur->right, right);
    // 偷 子节点不能偷
    res[1] = cur->val + left[0] + right[0];
    // 不偷，子节点可偷可不偷，二选一选择最大值！然后加起来
    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
  }

 public:
  int rob(TreeNode* root) {
    int res[2] = {0, 0};
    robTree(root, res);
    return res[0] > res[1] ? res[0] : res[1];
  }
};