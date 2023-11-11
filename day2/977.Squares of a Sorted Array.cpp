/**
 * @Date: 2023 Nov 09
 * @Time: 19:02
 * @Author: Chris
 * @Desc: this is very niubi
 **/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> sortedSquares(vector<int> &nums) {
    int it = nums.size() - 1;
    vector<int> res(nums.size(), 0);
    for (size_t i = 0, j = nums.size() - 1; i <= j; it--) {
      int lsquare = nums[i] * nums[i];
      int rsquare = nums[j] * nums[j];
      if (lsquare < rsquare) {
        res[it] = rsquare;
        j--;
      } else {
        res[it] = lsquare;
        i++;
      }
    }

    return res;
  }
};
int main() {
  vector<int> nums = {1, 2, 3, 4};
  Solution s = Solution();
  s.sortedSquares(nums);
  printf("hello world!");
  return 0;
}