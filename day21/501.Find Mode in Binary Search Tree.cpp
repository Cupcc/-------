/**
 * @Date: 2023 Dec 15
 * @Time: 21:06
 * @Author: Chris
 * @Title: 501.Find Mode in Binary Search Tree
 * @Link:
 *https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/
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
 private:
  int maxCount = 0;
  int count = 0;
  TreeNode* pre = nullptr;
  vector<int> res;

 public:
  void searchBST(TreeNode* cur) {
    if (cur == nullptr) return;
    if (cur->left) searchBST(cur->left);
    if (pre == nullptr) {
      count = 1;
    } else if (pre->val == cur->val) {
      count++;
    } else {
      count = 1;
    }
    pre = cur;

    if (count == maxCount) { //加入
      res.emplace_back(cur->val);
    }
    if (count > maxCount) { //清空此时计数器
      maxCount = count;
      res.clear();
      res.emplace_back(cur->val);
    }
    if (cur->right) searchBST(cur->right);
    return;
  }
  vector<int> findMode(TreeNode* root) {
    searchBST(root);
    return res;
  }
};
int main() { return 0; }