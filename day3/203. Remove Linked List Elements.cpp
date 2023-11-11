/**
 * @Date: 2023 Nov 12
 * @Time: 00:27
 * @Author: Chris
 * @Desc: 203. Remove Linked List Elements
 **/
#include <iostream>
#include <vector>
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
 // 虚拟头节点
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* _dummyHead = new ListNode(0, head);
    ListNode* cur = _dummyHead;
    while (cur->next != nullptr) {
      if (cur->next->val == val) {
        ListNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        temp = nullptr;
      } else { //我们始终判断的是cur->next所以，当cur->next被删除的时候，不需要移动 cur。
        cur = cur->next;
      }
    }
    delete _dummyHead;
    _dummyHead = nullptr;
    return head;
  }
};

int main() {
  ListNode* head = new ListNode();
  vector<int> list{1, 2, 6, 3, 4, 5, 6};
  ListNode* cur = head;
  for (auto item : list) {
    cur->next = new ListNode(item);
    cur = cur->next;
    cout << cur->val << " ";
  }
  Solution* s = new Solution();
  s->removeElements(head->next, 0);
  return 0;
}