/**
 * @date: 2024 Jan 07
 * @time: 23:17
 * @author: Chris
 * @title: 84. Largest Rectangle in Histogram
 * @link: https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
**/
package day60

// 找每个柱子左右两侧第一个小于该柱子的柱子
// 找小的，需要维护一个单调递增栈
func largestRectangleArea(heights []int) int {
	heights = append(heights, 0)
	stack := []int{-1}
	maxArea := 0

	for i, h := range heights {
		// 维护递减栈，寻找两侧第一个小的竹子
		for len(stack) > 1 && h < heights[stack[len(stack)-1]] {
			topIndex := stack[len(stack)-1] // 栈顶元素的索引
			stack = stack[:len(stack)-1]    // 出栈

			//计算面积
			width := i - stack[len(stack)-1] - 1
			maxArea = max(maxArea, heights[topIndex]*width)
		}
		stack = append(stack, i) // 当前柱子入栈，记录索引值
	}
	return maxArea
}
