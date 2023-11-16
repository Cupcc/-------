/**
 * @Date: 2023 Nov 13
 * @Time: 23:39
 * @Author: Chris
 * @Desc: 24. Swap Nodes in Pairs
 * @Link: https://leetcode.cn/problems/swap-nodes-in-pairs/
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
  ListNode* swapPairs(ListNode* head) {
    // less than 2 nodes,return head.
    if (head == nullptr || head->next == nullptr) return head;
    // New head is the second node.
    ListNode* newHead = head->next;
    ListNode* first = head;
    ListNode* second = first->next;
    ListNode* temp;

    while (1) {
      temp = second->next;   // 保存下一个first节点
      second->next = first;  // 第二个节点指向第一个

      // 设置第一个节点，如果
      // 0. 没有节点，return.
      // 1. 后面还剩一个节点，直接插上下一个 first，return.
      // 2. 后面还有 2 个节点，插入到第二个。继续。
      if (temp == nullptr) {  // 0.
        first->next = nullptr;
        return newHead;
      } else if (temp->next == nullptr) {  // 1
        first->next = temp;
        return newHead;
      } else {
        first->next = temp->next;  // 2.
        // 移动
        first = temp;
        second = temp->next;
      }
    }
    return newHead;
  }
  // recursion
  // 从后往前操作。操作顺序要相反。
  ListNode* swapPairs2(ListNode* head) {
    // 如果没有节点或 1 个节点
    if (!head || !head->next) return head;
    // 一定是 2 个节点
    ListNode* newHead = head->next;

    // 顺序可以改变
    // 先修改第一个节点,    // 再修改第二个节点。
    head->next = swapPairs2(newHead->next);
    newHead->next = head;
    
    // // 先修改第二个节点，再修改第一个节点
    // head->next = newHead->next;  // 先保存下一个节点,需要用到。
    // newHead->next = head;
    // head->next = swapPairs2(head->next);

    return newHead;
  }
};

class Solution2 {
 public:
  ListNode* swapPairs(ListNode* head) {
    // 使用虚拟节点，一次修改3个指针，

    ListNode* dummyNode = new ListNode();
    dummyNode->next = head;
    ListNode* cur = dummyNode;
    // 下一轮必须有2 个，如果有1个或没有，就不用操作。
    while (cur->next != nullptr && cur->next->next != nullptr) {
      ListNode* tmp = cur->next;               // 保存第1个
      ListNode* tmp1 = cur->next->next->next;  // 下一个轮第1个
      cur->next = cur->next->next;  // 1. 当前节点连接到 第2个
      cur->next->next = tmp;        // 2. 第2个节点连接到第1个
      cur->next->next->next = tmp1;  // 3. 第1个节点连接到下一轮第1 个
      // 移动。
      cur = cur->next->next;  // 移动 2 位，
    }
    return dummyNode->next;
  }
};

int main() {
  int test[] = {4, 3, 2, 1};
  ListNode* rear = new ListNode();
  for (size_t i = 0; i < 4; i++) {
    ListNode* newNode = new ListNode(test[i], rear);
    rear = newNode;
    // cout << newNode->val << " ";
  }

  // for (size_t i = 0; i < 4; i++) {
  //   cout << rear->val << " ";
  //   rear = rear->next;
  // }
  Solution* a = new Solution();
  a->swapPairs(rear);
  return 0;
}