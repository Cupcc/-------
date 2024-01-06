/**
 * @date: 2024 Jan 06
 * @time: 15:18
 * @author: Chris
 * @title: 1005. Maximize Sum Of Array After K Negations
 * @link: https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/
**/
package day34

import (
	"math"
	"sort"
)

// 按绝对值排序，这样只用翻转数组最后一个
func largestSumAfterKNegations(nums []int, k int) int {
	// 绝对值从大到小排序
	sort.Slice(nums, func(i, j int) bool {
		return math.Abs(float64(nums[i])) > math.Abs(float64(nums[j]))
	})
	for i := 0; i < len(nums); i++ {
		if k > 0 && nums[i] < 0 {
			nums[i] *= -1
			k--
		}
	}
	if k%2 == 1 {
		nums[len(nums)-1] *= -1
	}
	res := 0
	for _, num := range nums {
		res += num
	}
	return res
}

// 从小到大，依次翻转所有负数
// 如果还有剩余次数，一直翻转“当前”最小的数。（这个数可能是翻转后得到的正数）
func largestSumAfterKNegations2(nums []int, k int) int {
	sort.Ints(nums)
	i := 0
	for ; i < len(nums) && nums[i] < 0 && i < k; i++ {
		nums[i] *= -1
	}
	// 如果还有剩余次数
	if i < k && (k-i)%2 == 1 {
		// 如果没有剩余元素，翻转最后一个
		if i == len(nums) {
			nums[i-1] *= -1
		} else { // 如果有剩余，翻转
			// 选择中间2个最小的一个正数
			// 如果是nums[0]，防止数组越界
			if i == 0 || nums[i] < nums[i-1] {
				nums[i] *= -1
			} else {
				nums[i-1] *= -1
			}
		}

	}
	res := 0
	for _, num := range nums {
		res += num
	}
	return res
}
