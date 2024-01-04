/**
 * @date: 2024 Jan 04
 * @time: 22:10
 * @author: Chris
 * @title: 739. Daily Temperatures
 * @link: https://leetcode.cn/problems/daily-temperatures/description/
**/
package day58

// 找右侧第一个大于该元素的值。
// [4, 1, 5, 9] 第一个大于4的值为5,第一个大于1的也为5
// 答案 [5, 5, 9, -1]
// 栈中元素是单调的，递增或递减
func dailyTemperatures(temperatures []int) []int {
	result := make([]int, len(temperatures))

	for i := range result {
		result[i] = 0
	}

	var stack []int

	for i, tem := range temperatures {
		// 非空栈，  当前元素 >  栈顶元素
		for len(stack) > 0 && tem > temperatures[stack[len(stack)-1]] {
			topIndex := stack[len(stack)-1]
			// 就找到了大于栈顶的元素！且它是第一个大于栈顶的！
			// 给栈顶元素标记一下，该元素的位置！
			result[topIndex] = i - topIndex

			stack = stack[:len(stack)-1]
		}
		// 把数组中的每一个元素都加入栈中
		stack = append(stack, i)
	}
	return result
}
