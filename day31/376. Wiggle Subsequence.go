/**
 * @date: 2024 Jan 06
 * @time: 11:57
 * @author: Chris
 * @title: Input the description of this file
 * @link: Link url
**/
package day31

func wiggleMaxLength(nums []int) int {
	n := len(nums)
	if n < 2 {
		return n
	}

	// 记录第一个差
	res := 1
	preDiff := nums[1] - nums[0]
	if preDiff != 0 {
		// 初始化
		res = 2
	}

	// 从第3个元素遍历
	for i := 2; i < n; i++ {
		diff := nums[i] - nums[i-1]
		// 当前差diff与preDiff异号，变化相反说明有峰值，记录下来
		// diff不包含0，排除平坡
		if diff > 0 && preDiff <= 0 || diff < 0 && preDiff >= 0 {
			res++
			preDiff = diff
		}
	}
	return res
}
