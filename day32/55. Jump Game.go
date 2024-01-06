/**
 * @date: 2024 Jan 06
 * @time: 13:32
 * @author: Chris
 * @title: 55. Jump Game
 * @link: https://leetcode.cn/problems/jump-game/description/
**/
package day32

// 跳跃覆盖范围究竟可不可以覆盖到终点！
func canJump(nums []int) bool {
	if len(nums) == 1 {
		return true
	}
	// 记录 能到达的最大的位置
	cover := 0

	// 注意这里i的范围是cover，是能到达的距离！超过这个距离不能到达
	for i := 0; i <= cover; i++ {
		// 更新cover = (当前位置+跳跃距离, 旧cover)
		cover = max(i+nums[i], cover)
		if cover >= len(nums)-1 {
			return true
		}
	}
	return false
}
