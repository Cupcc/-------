/**
 * @date: 2024 Jan 04
 * @time: 23:35
 * @author: Chris
 * @title: 496. Next Greater Element
 * @link: https://programmercarl.com/0496.下一个更大元素I.html
**/

package day58

// nums2用单调栈找到右侧第一个最大的值，并用map记录结果
// 然后映射给nums1
func nextGreaterElement(nums1 []int, nums2 []int) []int {
	stack := []int{}

	// map = (栈顶元素 : 右侧第一个大于自己的元素)
	nextGreater := make(map[int]int)

	// 根据单调栈的步骤，记录下来，
	// 因为题目中要求是nums1中元素在nums2中元素xxxx，
	// 所以这里这里记录的是元素-元素的映射，不是索引-元素。
	for _, num := range nums2 {
		for len(stack) > 0 && num > stack[len(stack)-1] {
			top := stack[len(stack)-1]
			nextGreater[top] = num
			stack = stack[:len(stack)-1]
		}
		stack = append(stack, num)
	}

	// 栈里的元素都是 不存在 右侧 大于自己的元素
	for len(stack) > 0 {
		top := stack[len(stack)-1]   // 栈顶元素
		nextGreater[top] = -1        //  置为-1
		stack = stack[:len(stack)-1] //出栈
	}

	// 记录答案
	result := make([]int, len(nums1))
	for i, num := range nums1 {
		result[i] = nextGreater[num] // 查表
	}
	return result
}
