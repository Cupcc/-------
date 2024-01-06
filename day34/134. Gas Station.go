/**
 * @date: 2024 Jan 06
 * @time: 16:12
 * @author: Chris
 * @title: 134. Gas Station
 * @link: https://leetcode.cn/problems/gas-station/description/
**/

package day34

func canCompleteCircuit(gas []int, cost []int) int {
	curSum := 0
	totalSum := 0
	start := 0
	for i := 0; i < len(gas); i++ {
		totalSum += gas[i] - cost[i] // 累加所有的剩余油量
		curSum += gas[i] - cost[i]   // 累加剩余油量,如果一直>0说明，我们一直可以达到下一个位置！
		if curSum < 0 {              // 如果剩余油量不可达
			start = i + 1 // 当前位置i不行，记录下一个位置
			curSum = 0    // 如果不行，从当前位置累加
		}
	}

	if totalSum < 0 {
		return -1
	}
	return start
}
