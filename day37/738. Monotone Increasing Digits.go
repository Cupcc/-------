/**
 * @date: 2024 Jan 07
 * @time: 23:48
 * @author: Chris
 * @title: 738. Monotone Increasing Digits
 * @link: https://leetcode.cn/problems/monotone-increasing-digits/description/
**/
package day37

import "strconv"

// 小于n的最大正数，需要满足各个位依次递增
func monotoneIncreasingDigits(n int) int {
	// 从后向前遍历，不改变高位的结果
	s := strconv.Itoa(n)
	ss := []byte(s)

	if len(ss) <= 1 {
		return n
	}
	// 从低位向高位遍历，确保值最大
	for i := len(ss) - 1; i > 0; i-- {
		// 高位大于低位，高位-1，后面全部置为9
		if ss[i-1] > ss[i] {
			ss[i-1] -= 1
			for j := i; j < len(ss); j++ {
				ss[j] = '9'
			}
		}
	}
	res, _ := strconv.Atoi(string(ss))
	return res
}
