/**
 * @date: 2024 Jan 05
 * @time: 18:34
 * @author: Chris
 * @title: 503. Next Greater Element II
 * @link: https://leetcode.cn/problems/next-greater-element-ii/
**/
package day59

func nextGreaterElements(nums []int) []int {
	res := make([]int, len(nums))
	stack := []int{}

	for i := range res {
		res[i] = -1
	}

	for i := 0; i < len(nums)*2; i++ {
		index := i % len(nums)
		// 找到栈顶索引对应元素的值，栈顶元素为索引
		for len(stack) > 0 && nums[index] > nums[stack[len(stack)-1]] {
			// 栈顶索引 为 栈顶元素
			topIndex := stack[len(stack)-1]
			// 在索引位置 标记 元素值
			res[topIndex] = nums[index]
			// 出栈
			stack = stack[:len(stack)-1]
		}
		// 索引入栈
		stack = append(stack, index)
	}
	return res
}
