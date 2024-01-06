/**
 * @date: 2024 Jan 06
 * @time: 13:18
 * @author: Chris
 * @title: 53. Maximum Subarray
 * @link: https://leetcode.cn/problems/maximum-subarray/
**/
package day31

func maxSubArray(nums []int) int {
	count := 0
	maxSum := nums[0]
	for i := 0; i < len(nums); i++ {
		count += nums[i]
		if count > maxSum {
			maxSum = count
		}
		if count <= 0 {
			count = 0
		}
	}
	return maxSum
}
