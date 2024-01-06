/**
 * @date: 2024 Jan 06
 * @time: 13:44
 * @author: Chris
 * @title: 45. Jump Game II
 * @link: https://leetcode.cn/problems/jump-game-ii/description/
**/
package day32

// 记录步骤规则：每超过上一次可达最大范围，需要跳跃一次，次数+1
// 记录位置：i == lastDistance + 1
func jump(nums []int) int {
	// 根据题目规则，初始位置为nums[0]
	lastDistance := 0 // 上一次覆盖范围
	curDistance := 0  // 当前覆盖范围（可达最大范围）
	minStep := 0      // 记录最少跳跃次数

	for i := 0; i < len(nums); i++ {
		if i == lastDistance+1 { // 在上一次可达范围+1的位置，记录步骤
			minStep++                  // 跳跃次数+1
			lastDistance = curDistance // 记录时才可以更新
		}
		curDistance = max(nums[i]+i, curDistance) // 更新当前可达的最大范围
	}
	return minStep
}
