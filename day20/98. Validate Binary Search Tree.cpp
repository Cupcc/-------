/**
 * @Date: 2023 Dec 14
 * @Time: 22:44
 * @Author: Chris
 * @Title: 98. Validate Binary Search Tree
 * @Link: https://leetcode.cn/problems/validate-binary-search-tree/description/
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
  // 中序遍历下的数组是否符合严格递增序列
  vector<int> vec;
  void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    vec.emplace_back(root->val);
    inorderTraversal(root->right);
  }
  bool isValidBST(TreeNode* root) {
    vec.clear();
    inorderTraversal(root);
    return std::is_sorted(vec.begin(), vec.end(),
                          [](int a, int b) { return a <= b; });
  }
};
int main() {
  Solution solution;
  TreeNode* root1 = nullptr;
  std::cout << "Test case 1: "
            << (solution.isValidBST(root1) == true ? "PASS" : "FAIL")
            << std::endl;

  TreeNode* root2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
  std::cout << "Test case 2: "
            << (solution.isValidBST(root2) == true ? "PASS" : "FAIL")
            << std::endl;

  TreeNode* root3 = new TreeNode(2, new TreeNode(2), new TreeNode(2));
  std::cout << "Test case 3: "
            << (solution.isValidBST(root3) == false ? "PASS" : "FAIL")
            << std::endl;

  return 0;
}