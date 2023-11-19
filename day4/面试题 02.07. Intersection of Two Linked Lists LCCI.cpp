/**
 * @Date: 2023 Nov 17
 * @Time: 19:35
 * @Author: Chris
 * @Desc: 面试题 02.07. Intersection of Two Linked Lists LCCI
 * @Link:
 *https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
 **/
#include <unistd.h>

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
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode *curA, *curB;
    curA = headA;
    curB = headB;
    size_t sizeA = 0, sizeB = 0;
    while (curA != nullptr) {
      curA = curA->next;
      sizeA++;
    }
    while (curB != nullptr) {
      curB = curB->next;
      sizeB++;
    }
    curA = headA;
    curB = headB;
    // 确保 a 是最大的
    if (sizeB > sizeA) {
      swap(sizeA, sizeB);
      swap(curA, curB);
    }
    int gap = sizeA - sizeB;
    while (gap--) {
      curA = curA->next;
    }
    while (curA != nullptr) {
      if (curA == curB) {
        return curA;
      }
      curA = curA->next;
      curB = curB->next;
    }
    return nullptr;
  }
};
int main() { return 0; }