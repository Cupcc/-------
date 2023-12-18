/**
 * @Date: 2023 Dec 18
 * @Time: 22:40
 * @Author: Chris
 * @Title: 108. Convert Sorted Array to Binary Search Tree
 * @Link:
 *https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
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
 // 找到中间节点进行构造
  TreeNode* traversal(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = traversal(nums, left, mid - 1);
    root->right = traversal(nums, mid + 1, right);
    return root;
  }
  /// @brief convert sorted array to binary search tree (height-balanced)
  /// @param nums
  /// @return
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = traversal(nums, 0, nums.size() - 1);
    return root;
  }
};

int main() { return 0; }