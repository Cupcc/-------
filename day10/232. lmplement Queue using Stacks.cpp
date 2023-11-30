/**
 * @Date: 2023 Nov 30
 * @Time: 20:47
 * @Author: Chris
 * @Desc: 232. lmplement Queue using Stacks
 * @Link: https://leetcode.cn/problems/implement-queue-using-stacks/description/
 **/
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
 public:

 //双向栈
 stack<int> stackIn;
 stack<int> stackOut;
    MyQueue(){
        
    }
    void push(int x){
        stackIn.push(x);
    }
    int pop(){
        // 如果出栈非空，直接出
        // 如果出栈是空，需要将入站全部压入出栈，这样才可以获得队列的头。
        if(stackOut.empty()){
            while(!stackIn.empty()){
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int queuePop = stackOut.top();
        stackOut.pop();
        return queuePop;
    }
    int peek(){
        int res = this->pop();
        stackOut.push(res);
        return res;
    }
    bool empty(){
        return stackIn.empty() && stackOut.empty();
    }
};

int main() {
  return 0;
}