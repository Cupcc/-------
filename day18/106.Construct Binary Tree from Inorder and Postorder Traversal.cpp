/**
 * @Date: 2023 Dec 13
 * @Time: 14:28
 * @Author: Chris
 * @Title: 106.Construct Binary Tree from Inorder and Postorder Traversal
 * @Link:
 *https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
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
  TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
    // 1.以后序为判断，
    // 2. 分割
    //     a.在中序中分割，
    //     b.在后序中分割
    // 后序为0结束
    if (postorder.size() == 0) return nullptr;

    int rootValue = postorder[postorder.size() - 1];
    TreeNode* root = new TreeNode(rootValue);

    // 叶子
    if (postorder.size() == 1) return root;

    // 切割
    int delimiterIndex;
    for (delimiterIndex = 0; delimiterIndex < inorder.size();
         ++delimiterIndex) {
      if (inorder[delimiterIndex] == rootValue) break;
    }

    // 切割中序
    //[0, delimiterIndex)
    vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
    //[delimiterIndex+1, end)
    vector<int> rightInorder(inorder.begin() + delimiterIndex + 1,
                             inorder.end());

    // postOrder丢掉末尾
    postorder.resize(postorder.size() - 1);
    // 切割后序
    //[0, leftInorder.size())
    vector<int> leftPostorder(postorder.begin(),
                              postorder.begin() + leftInorder.size());
    // [leftInorder.size(), end)
    vector<int> rightPostorder(postorder.begin() + leftInorder.size(),
                               postorder.end());
    // 构建左子树
    root->left = traversal(leftInorder, leftPostorder);
    // 构建右子树
    root->right = traversal(rightInorder, rightPostorder);
    return root;
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
    return traversal(inorder, postorder);
  }
};
int main() { return 0; }