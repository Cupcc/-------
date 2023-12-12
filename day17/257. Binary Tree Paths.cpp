/**
 * @Date: 2023 Dec 12
 * @Time: 14:37
 * @Author: Chris
 * @Title: 257. Binary Tree Paths
 * @Link: https://leetcode.cn/problems/binary-tree-paths/
 **/
#include <iostream>
#include <string>
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
  vector<string> res;

  void search(TreeNode* node, vector<int> &path) {
    path.emplace_back(node->val);
    if (!node->left && !node->right) {
      string sPath;
      for (int i = 0; i < path.size() - 1; ++i) {
        sPath += to_string(path[i]);
        sPath += "->";
      }
      sPath += to_string(node->val);
      res.emplace_back(sPath);
      return;
    }
    if (node->left) {
      search(node->left, path);
      path.pop_back();
    }
    if (node->right) {
      search(node->right, path);
      path.pop_back();
    }
  }

  vector<string> binaryTreePaths(TreeNode* root) {
    vector<int> path;
    if(!root) return res;
    search(root,path);
    return res;
  }
};
// 测试用例
int main() {

   // 创建一棵二叉树
   TreeNode* root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left ->right= new TreeNode(5);

   // 创建Solution对象
   Solution solution;

   // 调用binaryTreePaths函数进行测试
   vector<string> paths = solution.binaryTreePaths(root);

   // 打印结果
   for (const auto& path : paths) {
       cout << path << endl;
    }

    return 0;
}