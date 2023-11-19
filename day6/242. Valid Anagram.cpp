/**
 * @Date: 2023 Nov 19
 * @Time: 16:55
 * @Author: Chris
 * @Desc: 242. Valid Anagram
 * @Link: https://leetcode.cn/problems/valid-anagram/description/
 **/
#include <iostream>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    // create hash list
    int record[26] = {0};
    for (size_t i = 0; i < s.size(); i++) {
      record[s[i] - 'a']++;
    }
    for (size_t i = 0; i < t.size(); i++) {
      record[t[i] - 'a']--;
    }
    for (size_t i = 0; i < 26; i++) {
      if (record[i] != 0) return false;
    }
    return true;
  }
};
int main() { return 0; }