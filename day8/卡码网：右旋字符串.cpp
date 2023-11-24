/** 
 * @Date: 2023 Nov 24
 * @Time: 00:29
 * @Author: Chris
 * @Desc: Input the description of this file
 * @Link: Paste the Link
**/
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
 public:
 // 先整体反转，再局部反转
  void rightRotateString(string & s,int n) {
    int len = s.size();
    reverse(s.begin(), s.end());
    reverse(s.begin(),s.begin()+n);
    reverse(s.begin()+n, s.end());
}
};
int main() {
    
    return 0;
}