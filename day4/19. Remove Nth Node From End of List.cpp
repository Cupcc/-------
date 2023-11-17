/**
 * @Date: 2023 Nov 17
 * @Time: 00:45
 * @Author: Chris
 * @Desc: Remove Nth Node from End of List
 * @Link:
 *https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 **/
#include <iostream>

using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    //直接操作，需要边缘处理
    size_t size = 0;
    ListNode* cur = head;
    while (cur != nullptr) {
      size++;
      cur = cur->next;
    }
    // 头节点删除的边缘处理
    if (n == size){
        return head->next;
    }
    cur = head;
    ListNode* pre = nullptr;
    for (size_t i = 0; i < size - n; i++) {
      pre = cur;
      cur = cur->next;
    }
    pre->next = cur->next;
    delete cur;
    cur = nullptr;
    return head;
  }
};
int main() { return 0; }
