/**
 * @Date: 2023 Nov 20
 * @Time: 20:10
 * @Author: Chris
 * @Desc: 383. Ransom Note
 * @Link: https://leetcode.cn/problems/ransom-note/description/
 **/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  // map 消耗大，底层为 hash，需要计算 hash 值和处理hash 碰撞
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> umap;
    for (char ch : magazine) {
      umap[ch]++;
    }
    for (char ch : ransomNote) {
      umap[ch]--;
      if (umap[ch] < 0) {
        return false;
      }
    }
    return true;
  }

  // 数组实现
  bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() > magazine.size()) return false;
    int record[26] = {0};
    for (char ch : magazine) {
      record[ch - 'a']++;
    }
    for (char ch : ransomNote) {
      record[ch - 'a']--;
      if (record[ch - 'a'] < 0) return false;
    }
    return true;
  }
};

int main() { return 0; }