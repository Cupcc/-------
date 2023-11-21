/**
 * @Date: 2023 Nov 20
 * @Time: 01:40
 * @Author: Chris
 * @Desc: 454. 4Sum II
 * @Link: https://leetcode.cn/problems/4sum-ii/description/
 **/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    unordered_map<int, int> umap;  // key = a+b的数值, value为和出现的次数
    for (int num1 : nums1) {
      for (int num2 : nums2) {
        umap[num1 + num2]++;
      }
    }

    int count = 0;  // count a+b+c+d=0 出现的次数
    // a+b = 0-(c+d)
    for (int num3 : nums3) {
      for (int num4 : nums4) {
        // 如果不存在key,会自动插入key,并返回value=0.
        count += umap[0 - (num3 + num4)];
      }
    }
    return count;
  }
};
int main() { return 0; }