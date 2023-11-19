/**
 * @Date: 2023 Nov 18
 * @Time: 21:35
 * @Author: Chris
 * @Desc: 142. Linked List Cycle II
 * @Link: https://leetcode.cn/problems/linked-list-cycle-ii/description/
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
 // 快慢指针
  ListNode* detectCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    // 没有环,因为fast要一次移动2个单位，所以也要判断fast->next
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        ListNode* index1 = fast;  // 从相遇的地方出发
        ListNode* index2 = head;  // 从出发
        while (index1 != index2) {
          index1 = index1->next;
          index2 = index2->next;
        }
        return index2;
      }
    }
    return nullptr;
  }
};
int main() { return 0; }