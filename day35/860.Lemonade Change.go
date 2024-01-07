/**
 * @date: 2024 Jan 07
 * @time: 20:26
 * @author: Chris
 * @title: 860.Lemonade Change
 * @link: https://leetcode.cn/problems/lemonade-change/
**/

package day35

func lemonadeChange(bills []int) bool {
	five := 0
	ten := 0
	for _, bill := range bills {
		// 从大到小判断
		// 先找大的，找不开，给小的
		if bill == 20 {
			if ten > 0 {
				ten--
				five--
			} else {
				five -= 3
			}
		} else if bill == 10 {
			five--
			ten++
		} else {
			five++
		}
		if five < 0 {
			return false
		}
	}
	return true
}
