
/**
 * @Date: 2023 Nov 11
 * @Time: 01:38
 * @Author: Chris
 * @Desc: Input the description of this file
 **/
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  struct ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class MyLinkedList {
 private:
  ListNode* _dummyHead;
  int _size;

 public:
  // 初始化
  MyLinkedList() {
    _dummyHead = new ListNode(0);
    _size = 0;
  }
  int get(int index) {
    if (index >= _size || index < 0) {
      return -1;
    }
    ListNode* cur = _dummyHead->next;
    while (index--) {
      cur = cur->next;
    }
    return cur->val;
  }
  void addAtHead(int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = _dummyHead->next;
    _dummyHead->next = newNode;
    _size++;
  }
  void addAtTail(int val) {
    ListNode* cur = _dummyHead;
    while (cur->next != nullptr) {
      cur = cur->next;
    };
    cur->next = new ListNode(val);
    _size++;
  }
  void addAtIndex(int index, int val) {
    if (index > _size || index < 0) {  // index =_size可以插入到尾部
      cout << "the index is out of range" << endl;
      return;
    }
    ListNode* newNode = new ListNode(val);
    ListNode* cur = _dummyHead;
    while (index--) {
      cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    _size++;
  }
  void deleteAtIndex(int index) {
    if (index > _size || index < 0) {
      return;
    }
    ListNode* cur = _dummyHead;
    while (index--) {
      cur = cur->next;
    }
    ListNode* tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
    tmp = nullptr;
    _size--;
  }
  void printMyLinkedList() {
    ListNode* cur = _dummyHead;
    for (size_t i = 0; cur != nullptr; i++) {
      cout << "Node" << i << ": "
           << "val = " << cur->val << endl;
      cur = cur->next;
    }
  }
};

int main() { return 0; }
