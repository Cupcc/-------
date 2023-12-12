/**
 * @Date: 2023 Dec 12
 * @Time: 15:16
 * @Author: Chris
 * @Title: 404. Sum of Left Leaves
 * @Link: https://leetcode.cn/problems/sum-of-left-leaves/description/
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
  // 左子树的左结点之和+右子树的左节点之和
  int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr) return 0;
    //  if(root->left == nullptr && root->left == nullptr) return 0;
    int leftValue = sumOfLeftLeaves(root->left);
    if (root->left && root->left->left == nullptr &&
        root->left->right == nullptr) {
      leftValue += root->left->val;
    }
    int rightValue = sumOfLeftLeaves(root->right);
    int sum = leftValue + rightValue;
    return sum;
  }
  int simplified(TreeNode* root) {
    if (!root) return 0;
    int leftValue = 0;
    if (root->left and !root->left->left && !root->left->right) {
      leftValue = root->left->val;
    }
    return leftValue + sumOfLeftLeaves(root->left) +
           sumOfLeftLeaves(root->right);
  }
};
int main() { return 0; }