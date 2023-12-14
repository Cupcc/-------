/**
 * @Date: 2023 Dec 14
 * @Time: 21:34
 * @Author: Chris
 * @Title: 654. Maximum Binary Tree
 * @Link: https://leetcode.cn/problems/maximum-binary-tree/description/
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
  // 1. 寻找最大值，标记位置
  // 2. 寻找坐标最大值
  // 3. 寻找右边最大值
  // 构造树使用前序遍历
  // 确定终止条件，数组大小为1
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    TreeNode* node = new TreeNode();
    if (nums.size() == 1) {
      node->val = nums[0];
      return node;
    }
    int maxValue = 0;
    int maxValueIndex = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > maxValue) {
        maxValue = nums[i];
        maxValueIndex = i;
      }
    }
    node->val = maxValue;
    // 构建左子树
    if (maxValueIndex > 0) {
      vector<int> leftVec(nums.begin(), nums.begin() + maxValueIndex);
      node->left = constructMaximumBinaryTree(leftVec);
    }
    // 构建右子树
    if (maxValueIndex < nums.size() - 1) {
      vector<int> rightVec(nums.begin() + maxValueIndex + 1, nums.end());
      node->right = constructMaximumBinaryTree(rightVec);
    }
    return node;
  }
};
int main() { return 0; }