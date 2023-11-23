/**
 * @Date: 2023 Nov 24
 * @Time: 00:15
 * @Author: Chris
 * @Desc: 卡码网：54.替换数字
 * @Link: https://kamacoder.com/problempage.php?pid=1064
 **/
#include <iostream>

using namespace std;

class Solution {
 public:
  string replaceWithNumber(string s) {
    int count = 0;
    int oldSize = s.size();
    for (size_t i = 0; i < s.size(); i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        count++;
      }
    }
    // number 6 个 ,增加 5 个
    s.resize(s.size() + count * 5);
    int sNewSize = s.size();
    // rear to front
    for (int i = sNewSize - 1, j = oldSize - 1; j < i; i--, j--) {
      if (s[j] < '0' || s[j] > '9') {
        s[i] = s[j];
      } else {
        s[i--] = 'r';
        s[i--] = 'e';
        s[i--] = 'm';
        s[i--] = 'u';
        s[i] = 'n';
      }
    }
    return s;
  }
};
int main() { return 0; }