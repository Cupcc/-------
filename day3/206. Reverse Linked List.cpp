/**
 * @Date: 2023 Nov 12
 * @Time: 01:51
 * @Author: Chris
 * @Desc: 206. Reverse Linked List
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
  ListNode* reverseList(ListNode* head) {
    // 双指针
    ListNode* pre = nullptr;  // 可以适用于头节点
    ListNode* cur = head;
    ListNode* temp = nullptr;  // 用于保存cur->next
    while (cur != nullptr) {
      temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }
    return pre;  // 注意最后返回pre,cur指向空了。
  }
};
int main() { return 0; }