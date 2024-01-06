/**
 * @date: 2024 Jan 05
 * @time: 18:53
 * @author: Chris
 * @title: 42. Trapping Rain Water
 * @link: https://leetcode.cn/problems/trapping-rain-water/
**/

package day59

// 按列计算，求每一列的雨水量，然后累加起来
// 每一列的雨水量右 由左、右两侧最高柱子中较低的那个决定！
// size[i] = min(left_h, right_h) - height[i]
// double-pointer
func trap(height []int) int {
	if len(height) <= 2 {
		return 0
	}

	size := len(height)
	max_left := make([]int, size)
	max_right := make([]int, size)

	// Calculating maximum height to the left of each bar
	max_left[0] = height[0]
	for i := 1; i < size; i++ {
		max_left[i] = max(height[i], max_left[i-1])
	}

	// Calculating maximum height to the right of each bar
	max_right[size-1] = height[size-1]
	for i := size - 2; i >= 0; i-- {
		max_right[i] = max(height[i], max_right[i+1])
	}

	// Calculating the trapped water
	sum := 0
	for i := 0; i < size; i++ {
		count := min(max_left[i], max_right[i]) - height[i]
		if count > 0 {
			sum += count
		}
	}

	return sum
}

// 单调栈、横向计算雨水
// 维护一个单调递减的栈
// 当遇到比栈顶元素大的，即遇到凹槽。计算雨水量
// 栈 [6, 4, 3, 1]栈顶, 栈顶左侧的元素 为 左侧第一个最大柱子
func Trap(height []int) int {
	stack := []int{}
	sum := 0

	for i := 0; i < len(height); i++ {
		for len(stack) > 0 && height[i] > height[stack[len(stack)-1]] {
			mid := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			if len(stack) > 0 {
				// 栈顶元素左侧第一个高于自己的柱子的索引
				left_index := stack[len(stack)-1]
				// 高度计算和双指针的一致，找到边缘柱子的最低高度 - 去池底高度
				h := min(height[left_index], height[i]) - height[mid]
				// 宽度为两个柱子的距离
				w := i - left_index - 1
				sum += h * w
			}
		}
		stack = append(stack, i)
	}
	return sum
}
