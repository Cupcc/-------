/**
 * @Date: 2023 Dec 03
 * @Time: 19:33
 * @Author: Chris
 * @Desc: 347. Top K Frequent Elements
 * @Link: https://leetcode.cn/problems/top-k-frequent-elements/description/
 **/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  // 1. 要统计元素出现频率
  // 2. 对频率排序
  // 3. 找出前K个高频元素
 private:
  class mycomparison {
    //  小顶堆
   public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
      return lhs.second > rhs.second;
    }
  };

 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    // 要统计元素出现的频率
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      map[nums[i]]++;
    }

    // 对频率排序
    // 定义一个小顶堆，大小为k
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        pri_que;
    for (unordered_map<int, int>::iterator it = map.begin(); it != map.end();
         it++) {
      pri_que.push(*it);
      if (pri_que.size() > k) {
        pri_que.pop();
      }
    }
    vector<int> result(k);
    for (int i = k - 1; i >= 0; i--) {
      result[i] = pri_que.top().first;
      pri_que.pop();
    }
    return result;
  }
};

int main() { return 0; }